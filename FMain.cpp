#include "FMain.h"

extern const int SCREEN_WIDTH 800;
extern const int SCREEN_HEIGHT 600;
extern const int NUMBER_OF_PLAYERS 4;
extern Players players;
extern IsPlaying isplaying[NUMBER_OF_PLAYERS];
//extern int br[9];
//extern int ho[9];
extern int GolfCourseHeight[9];
extern int GolfCourseWidth[9];
extern golf_ball_position GolfBallPosition[9];
//extern int mapnow;
extern int ActiveGolfCourse;

void PickPlayers()
{
	DrawIMGAlpha(surf.InitPlayerSurface,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0,0,0,false);
	players.picked=Events(surf.InitPlayerSurface,players);				
	SDL_Flip(DSurface.ScreenSurface);
	
	if(players.picked)
	{
		if(!players.tournament)
		{
			for(int i=0; i < NUMBER_OF_PLAYERS; i++)
			{
				isplaying[i].ball=GolfBallPosition[players.selectMap-1];
			}
			ActiveGolfCourse=players.selectMap-1;
		}
		else
		{
			for(int i=0; i < NUMBER_OF_PLAYERS; i++)
			{
				isplaying[i].ball=GolfBallPosition[0];
			}
			ActiveGolfCourse=0;
		}
		BreddHojd(isplaying[0].ball);				
		bredd=GolfCourseWidth[ActiveGolfCourse];
		hojd=GolfCourseHeight[ActiveGolfCourse];
		yta=tyta[ActiveGolfCourse];
		BreddHojd(GolfBallPosition[ActiveGolfCourse]);
	}
}

//void LandSatt(int &isp)
void CheckBallLanded(int &current_player)
{
	if (isplaying[current_player].BallLanded == true || isplaying[current_player].BallInHole)
	{	
		isplaying[current_player].BallLanded = false;
        	isplaying[current_player].score++;
		
		if (isplaying[current_player].BallInHole)
		{
            		players.finished_hole++;
		}
        	
		if (players.finished_hole == players.players)
		{
			++ActiveGolfCourse;
			
			if(ActiveGolfCourse==9 || players.tournament==false)
			{
				if(players.tournament)
				{
					players.finished=true; //Gör det möjligt att komma in på highscore
					Highscore(DSurface.InitPlayerSurface,isplaying,players);						
				}
					
				for(int i=0; i < NUMBER_OF_PLAYERS; i++)
				{
					isplaying[i].BallInHole=false;
				}
				players = Players();
			}
			else
			{
				bredd=GolfCourseWidth[ActiveGolfCourse];
				hojd=GolfCourseHeight[ActiveGolfCourse];
				yta=tyta[ActiveGolfCourse];
				players.finished_hole = 0;
	
				for(int i=0; i<players.players; i++)
				{
					isplaying[i].BallInHole=false;					
					isplaying[i].ball=GolfBallPosition[ActiveGolfCourse];
				}
				current_player = 0;
	                	BreddHojd(isplaying[current_player].ball); //Centrerar skärmen
			}

			// Byt bana
		}
		else
		{
	                while (isplaying[(++current_player) % players.players].BallInHole == true) //Stegar frammåt till nästa spelare som itne satt den
					;

        	        current_player %= players.players;
                	BreddHojd(isplaying[current_player].ball);
		}
	}
}

//void MainEvents(Bools &bo,float &Rhojd,float &Rbredd,int x2,int y2,GolfClub &klubb,GolfClub klubbor[],int &isp,float &value)
void MainEvents(float &Rhojd,float &Rbredd,int x2,int y2,GolfClub &klubb,GolfClub klubbor[],int &isp,float &value)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT && FireGolfBall == false)
			{
				MouseDown = true;
			}
			else if(event.button.button == SDL_BUTTON_RIGHT)
			{
				MouseRightDown = true;
				if(RMove == false) 
				{
					RMove=true;
					Rhojd=hojd1;
					Rbredd=bredd1;
				}
			}
			break;

			case SDL_MOUSEBUTTONUP:
			if(event.button.button == SDL_BUTTON_LEFT && MouseDown == true)
			{						
				MouseDown=false;
				if(RMove==false)
				{
					if(PickGolfClub)
					{
						if((x2>640 && x2<793 && y2>10 && y2 <288 )) // Kollar om den är över klubb bilden
						{
							int tx,ty;
							x2 < ((640+793)/2) ? tx=0 : tx=3;
							ty = (y2-10)/(279/3);									
							klubb=klubbor[tx+ty];
							hitBoll(klubb,isplaying[isp].ball);
							bo.PickGolfClub=false;		
							isplaying[isp].ball.current_height=0;
						}
					}
					else if(SetValue)							
					{					
						SetValue=false;								
						FireGolfBall=true;
						float temp;
						value > 1.0f ? temp=2.0f-value : temp=value;
						if(temp<0.1f)
						{
							temp=0.1f;
						}
						isplaying[isp].ball.distance*=temp;
						isplaying[isp].ball.height*=temp;
					}
				}
			}

			if( event.button.button == SDL_BUTTON_RIGHT && MouseRightDown == true)
				MouseRightDown=false;
			break;

			case SDL_KEYDOWN:	
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						//EscMeny(DSurface.InitPlayerSurface, bo, players, isplaying);
						EscMeny(DSurface.InitPlayerSurface, players, isplaying);
					break;
					case SDL_QUIT:
						Done = true;					
					break;
				}
		}
	}
}

//void MainSkjut(bool &set,int &x2,int &y2,int &isp,GolfClub &klubb,Bools &bo, float &value,Pos &windPos,Pos &WPos)
void MainSkjut(bool &set,int &x2,int &y2,int &isp,GolfClub &klubb, float &value,Pos &windPos,Pos &WPos)
{
	static float tempX,tempY,atX,atY;

	if(set)
	{	
		atX=  ((x2-(isplaying[isp].ball.x-bredd1))/(sqrtf(powf(abs(x2-(isplaying[isp].ball.x-bredd1)),2)+powf(abs(y2-(isplaying[isp].ball.y-hojd1)),2))));
		atY=  ((y2-(isplaying[isp].ball.y-hojd1))/(sqrtf(powf(abs(x2-(isplaying[isp].ball.x-bredd1)),2)+powf(abs(y2-(isplaying[isp].ball.y-hojd1)),2))));
		set=false;
		if(klubb.height == 0)
		{
			snd.Putter();
		}
		else
		{
			snd.Driver();
		}
	}

	tempX= isplaying[isp].ball.distance*atX;
	tempY= isplaying[isp].ball.distance*atY;
	
	if(isplaying[isp].ball.height>0)
	{
		UseWind(FirstShot,windPos,WPos);
	}
	
	Direction x=CompPosX(bredd1,isplaying[isp].ball.x+tempX+windPos.x);
	Direction y=CompPosY(hojd1,isplaying[isp].ball.y+tempY+windPos.y);			
	

	if(bredd1+tempX+windPos.x < ((bredd-16)*50) && bredd1+tempX+windPos.x >0)
	{
		if((tempX+windPos.x > 0 && x==Right) || (tempX+windPos.x < 0 && x==Left) )
		{
			bredd1+= tempX+windPos.x;
		}
	}
	
	if(hojd1+tempY+windPos.y < ((hojd-12)*50) && hojd1+tempY+windPos.y > 0 )
	{
		if((tempY+windPos.y > 0 && y==Down) || (tempY+windPos.y < 0 && y==Up))
		{
			hojd1+= tempY+windPos.y;
		}
	}

	isplaying[isp].ball.x+=tempX;
	isplaying[isp].ball.x+=windPos.x;
	isplaying[isp].ball.y+=tempY;
	isplaying[isp].ball.y+=windPos.y;

	
	if(isplaying[isp].ball.x<bredd*50)
	{
		FireGolfBall=Skjut(isplaying[isp],isplaying[isp].ball,windPos,atX,atY,Ground);
	}
	if(FireGolfBall)
	{
		FireGolfBall=OutofBounds(isplaying[isp].ball,tempX+windPos.x,tempY+windPos.y);
	}
	if(isplaying[isp].BallInHole)
	{
		FireGolfBall=false;
	}
	
	if(FireGolfBall==false)
	{
		PickGolfClub=true;
		Ground=true;
		SetValue=true;
		Power=true;
		value=0;
		FirstShot=true;
		isplaying[isp].BallLanded=true;
		UseWind(FirstShot,windPos,WPos);			
	}
}

//void FireGolfBall(bool &set,int &x2,int &y2,int &isp,GolfClub &golfclub,Bools &bo, float &value,Pos &windPos,Pos &WPos)
void FireGolfBall(bool &set,int &x2,int &y2,int &isp,GolfClub &golfclub, float &value,Pos &windPos,Pos &WPos)
{
	static float tempX,tempY,atX,atY;

	if(set)
	{	
		atX=  ((x2-(isplaying[isp].ball.x-bredd1))/(sqrtf(powf(abs(x2-(isplaying[isp].ball.x-bredd1)),2)+powf(abs(y2-(isplaying[isp].ball.y-hojd1)),2))));
		atY=  ((y2-(isplaying[isp].ball.y-hojd1))/(sqrtf(powf(abs(x2-(isplaying[isp].ball.x-bredd1)),2)+powf(abs(y2-(isplaying[isp].ball.y-hojd1)),2))));
		set=false;
		if(golfclub.height == 0)
		{
			snd.Putter();
		}
		else
		{
			snd.Driver();
		}
	}

	tempX= isplaying[isp].ball.distance*atX;
	tempY= isplaying[isp].ball.distance*atY;
	
	if(isplaying[isp].ball.height>0)
	{
			UseWind(FirstShot,windPos,WPos);
	}
	
	Direction x=CompPosX(bredd1,isplaying[isp].ball.x+tempX+windPos.x);
	Direction y=CompPosY(hojd1,isplaying[isp].ball.y+tempY+windPos.y);			
	

	if(bredd1+tempX+windPos.x < ((bredd-16)*50) && bredd1+tempX+windPos.x >0)
	{
		if((tempX+windPos.x > 0 && x==Right) || (tempX+windPos.x < 0 && x==Left) )
		{
			bredd1+= tempX+windPos.x;
		}
	}
	
	if(hojd1+tempY+windPos.y < ((hojd-12)*50) && hojd1+tempY+windPos.y > 0 )
	{
		if((tempY+windPos.y > 0 && y==Down) || (tempY+windPos.y < 0 && y==Up))
		{
			hojd1+= tempY+windPos.y;
		}
	}
	
	isplaying[isp].ball.x+=tempX;
	isplaying[isp].ball.x+=windPos.x;
	isplaying[isp].ball.y+=tempY;
	isplaying[isp].ball.y+=windPos.y;

	if(isplaying[isp].ball.x<bredd*50)
	{
		FireGolfBall=Skjut(isplaying[isp],isplaying[isp].ball,windPos,atX,atY,Ground);
	}
	if(FireGolfBall)
	{
		FireGolfBall=OutofBounds(isplaying[isp].ball,tempX+windPos.x,tempY+windPos.y);
	}
	if(isplaying[isp].BallInHole)
	{
		FireGolfBall=false;
	}
	
	if(FireGolfBall==false)
	{
		PickGolfClub=true;
		Ground=true;
		SetValue=true;
		Power=true;
		value=0;
		FirstShot=true;
		isplaying[isp].BallLanded=true;
		UseWind(FirstShot,windPos,WPos);		
	}
}

//void EventHandler(Bools &bo,float &RHeight,float &RWidth,int x2,int y2,GolfClub &golfclub,GolfClub golfclubs[],int &isp,float &value)
void EventHandler(float &RHeight,float &RWidth,int x2,int y2,GolfClub &golfclub,GolfClub golfclubs[],int &isp,float &value)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button == SDL_BUTTON_LEFT && FireGolfBall==false)
				{					
					MouseDown=true;
				}

				else if(event.button.button == SDL_BUTTON_RIGHT)
				{
					MouseRightDown=true;
					if(RMove==false) //Koppiterar nuvarande positionerna så man kan röra sig fritt
					{
						RMove=true;
						RHeight=hojd1;
						RWidth=bredd1;
					}
				}
			break;

			case SDL_MOUSEBUTTONUP:
				if(event.button.button == SDL_BUTTON_LEFT && MouseDown==true)
					{						
						MouseDown=false;
						if(RMove==false)
						{
							if(PickGolfClub)
							{
								if((x2>640 && x2<793 && y2>10 && y2 <288 )) // Kollar om den är över klubb bilden
								{
									int tx,ty;
									x2 < ((640+793)/2) ? tx=0 : tx=3;
									ty = (y2-10)/(279/3);									
									golfclub=golfclubs[tx+ty];
									hitBoll(golfclub,isplaying[isp].ball);
									PickGolfClub=false;		
									isplaying[isp].ball.current_height=0;
								}
							}
														
									
							else if(SetValue)							
							{					
								SetValue=false;								
								FireGolfBall=true;
					
								float temp;
								value > 1.0f ? temp=2.0f-value : temp=value;
								if(temp<0.1f)
								temp=0.1f;

								isplaying[isp].ball.distance*=temp;
								isplaying[isp].ball.height*=temp;
								//animPlayer(value); //Vill inte animera spelare
							}
						}
					}

					if( event.button.button == SDL_BUTTON_RIGHT && MouseRightDown==true)
					{
						MouseRightDown=false;
					}
					break;

			case SDL_KEYDOWN:
				
				switch(event.key.keysym.sym)
				{
				
				case SDLK_ESCAPE:
					EscMeny(DSurface.InitPlayerSurface, players, isplaying);
				break;
			
				case SDL_QUIT:
					Done=true;					
				break;
			}
		}
	}
}
