#include "skjut.h"
//#include "funktioner.h"
//#include <math.h>
extern int **yta;
//extern float hojd1,bredd1;
using namespace std;

// Replacement function for Skjut and should be added to the header file later
bool Shoot(IsPlaying &play, GolfBall &Ball, Pos &Windpos, float &atX, float &atY, bool &ground)
{
	//boll.current_height += boll.height;
	Ball.setCurrentHeight( Ball.getCurrentHeight() + Ball.getHeight() );
	
	if(Ball.getCurrentHeight() > 0)
	{
		if(yta[(int)Ball.getX() / 50][(int)Ball.getY() / 50] == 4)
		{
			int CenterX = (int)(Ball.getX() / 50 )*50+25;
			int CenterY = (int)(Ball.getY() / 50 )*50+17;
			static int CX=-1,CY=-1;
			
			// What the BLIP! is this?
			bool tempbool=false;

			float tempX = Ball.getX()-atX,tempY = Ball.getY() - atY;
			float malLangd = sqrtf(powf(CenterX - tempX,2.0) + powf(CenterY - tempY,2.0));
			float bollLangd;
			
			if(Ball.getDistance() > malLangd)
			{
				bollLangd=malLangd;
			}
			else
			{
				bollLangd=Ball.getDistance();
			}

			tempX+=atX*bollLangd;
			tempY+=atY*bollLangd;

			if(sqrtf(powf((tempX - CenterX),2.0) + powf((tempY - CenterY),2.0)) < 15 && (CX!=CenterX || 
						CY!=CenterY) && Ball.getCurrentHeight() < 300) //Kollar om den rör träd
			{
				atX = (atX*Ball.getDistance() + Windpos.x) / Ball.getDistance();
				atY = (atY*Ball.getDistance() + Windpos.y) / Ball.getDistance();
				Windpos.x = 0;
				Windpos.y = 0;
				if(Ball.getHeight() > 0)
				{
					Ball.setHeight(0)
				}
				Ball.setDistance( Ball.getDistance() / 2 );

				CX = CenterX;
				CY = CenterY;
				if(abs(CenterX - tempX) < 4)
				{
					atY = -atY;
				}
				else if(abs(CenterY-tempY) < 4)
				{
					atX= -atX;
				}
				else if( (tempX > CenterX && tempY > CenterY) || (tempX < CenterX && tempY < CenterY))
				{
					float temp=atX;
					atX= -atY;
					atY= -temp;
				}
				else
				{
					//swap(atX,atY);
					float temp=atX;
					atX= atY;
					atY= temp;
				}
				snd.Three(); //Spelar träff av träd
			}		
		}

		//boll.height-=0.1f;
		Ball.setHeight( Ball.getHeight() - 0.1f );
		return true;
	}

	//boll.current_height=0;
	Ball.setCurrentHeight(0);

	if(ground)	// If ball reached the ground then set the angle
	{
		Ball.setDistance(Ball.getDistance() * 0.7 );
		//boll.distance*=0.7;
		//if(Windpos.x!=0 )
		atX= (atX*Ball.getDistance() + Windpos.x) / Ball.getDistance();
		//if(Windpos.y!=0) 
		atY= (atY*Ball.getDistance() + Windpos.y) / Ball.getDistance();

		Windpos.x=0;
		Windpos.y=0;
		ground=false;
	}	
	
	int var= yta[(int)Ball.getX()/50][(int)Ball.getY()/50]%50; //var bollen är

	switch(var)
	{
		case 13:
			InGoal(play);
			break;
		case 1:
			Ball.setDistance( Ball.getDistance() - 0.1f );
			//boll.distance-=0.1;
			break;
		case 2:
		case 5:
		case 6:
		case 7: 
		case 8: 
			Ball.setDistance(0);
			//boll.distance=0;
			snd.Water();
			break;
		case 3:
		case 9:
		case 10:
		case 11:
		case 12:
			Ball.setDistance(Ball.getDistance() - 0.5);
			//boll.distance-=0.5;
			break;
		case 4:
			InTerrain(play);
			Ball.setDistance(0);
			//boll.distance=0;
			break;
		}
		
		if(Ball.getDistance() > 0)
		{
			return true;
		}

	ground=true;
	InTerrain(play);
	
	return false;	
}

bool Skjut(IsPlaying &play, GolfBall &Ball, Pos &Windpos, float &atX, float &atY, bool &ground) //Allt som har med bollens skjutande att göra
{	
	//boll.current_height+=boll.height;
	Ball.setCurrentHeight( Ball.getCurrentHeight() + Ball.getHeight() );
	if(Ball.getCurrentHeight() > 0)
	{
		if(yta[(int)Ball.getX()/50][(int)Ball.getY()/50]==4)
		{
			int CenterX= (int)(Ball.getX()/50 )*50+25;
			int CenterY=(int)(Ball.getY()/50 )*50+17;
			static int CX=-1,CY=-1;
			
			bool tempbool=false;
			

			float tempX=Ball.getX()-atX,tempY=Ball.getY()-atY;
			float malLangd= sqrtf(powf(CenterX-tempX,2.0) + powf(CenterY-tempY,2.0));
			float bollLangd;
			
			if( Ball.getDistance() > malLangd)
			{
				bollLangd=malLangd;
			}
			else
				bollLangd= Ball.getDistance();

			tempX+=atX*bollLangd;
			tempY+=atY*bollLangd;			
			
			

			if(sqrtf(powf((tempX-CenterX),2.0) + powf((tempY-CenterY),2.0)) <15 && (CX!=CenterX || CY!=CenterY) && Ball.getCurrentHeight() < 300) //Kollar om den rör träd
			{	
				atX= (atX*Ball.getDistance() + Windpos.x)/(Ball.getDistance());
				atY= (atY*Ball.getDistance() + Windpos.y)/(Ball.getDistance());
				Windpos.x=0;
				Windpos.y=0;
				if(Ball.getHeight() > 0)
					Ball.setHeight(0); //boll.height=0;				
				Ball.setDistance(Ball.getDistance() / 2); //boll.distance/=2;

				CX=CenterX;
				CY=CenterY;
				if(abs(CenterX-tempX) < 4)
					atY= -atY;
				else if(abs(CenterY-tempY) < 4)
					atX= -atX;

				else if( (tempX > CenterX && tempY > CenterY) || (tempX < CenterX && tempY < CenterY))
				{
					float temp=atX;
					atX= -atY;
					atY= -temp;
				}
				else
				{
					//swap(atX,atY);
					float temp=atX;
					atX= atY;
					atY= temp;
				}
				snd.Three(); //Spelar träff av träd
			}		
		}

		//boll.height-=0.1f;
		Ball.setHeight(Ball.getHeight() - 0.1f);
		return true;
	}

	//boll.current_height=0;
	Ball.setCurrentHeight(0);

	if(ground)	//ifall den nått marken så sätts vinkeln
	{
		//boll.distance*=0.7;
		Ball.setDistance(Ball.getDistance() * 0.7f);
		//if(Windpos.x!=0 )
		atX= (atX*Ball.getDistance() + Windpos.x)/ Ball.getDistance();
		//if(Windpos.y!=0) 
		atY= (atY*Ball.getDistance() + Windpos.y)/ Ball.getDistance();

		Windpos.x=0;
		Windpos.y=0;
		ground=false;
	}	
		int var= yta[(int)Ball.getX()/50][(int)Ball.getY()/50]%50; //var bollen är

		switch(var)
		{
		case 13:
			InGoal(play);
		case 1:
			//boll.distance-=0.1;
			Ball.setDistance(Ball.getDistance() - 0.1f);
			break;
		case 2:
		case 5:
		case 6:
		case 7: 
		case 8: 
			Ball.setDistance(0);
			//boll.distance=0;
			snd.Water();
			break;
		case 3:
		case 9:
		case 10:
		case 11:
		case 12:
			Ball.setDistance(Ball.getDistance() -0.5f);
			//boll.distance-=0.5;
			break;
		case 4:
			InTerrain(play);
			Ball.setDistance(0);
			//boll.distance=0;
			break;
		}


		if(Ball.getDistance() > 0)
		return true;

	ground=true;
	InTerrain(play);

	return false;
}

void hitBoll(GolfClub klubba,GolfBall &Ball) //initierar bollens möjligheter
{
	//boll.height = klubba.height;
	Ball.setHeight(klubba.height);
	//boll.distance = klubba.distance;
	Ball.setDistance(klubba.distance);
}


Direction CompPosX(float bredd1,float position) // kollar om vart den ska röra sig med hjälp av musen
{
	if(position-bredd1 > 600) 
		return Right;

	if( position-bredd1 < 200)
		return Left;

	return None;
}

Direction CompPosY(float hojd1,float position) // kollar om vart den ska röra sig med hjälp av musen
{
	if(position-hojd1 > 450) 
		return Down;

	if( position-hojd1 < 150)
		return Up;

	return None;
}


bool CheckXY(float x,float y) //Kollaro m dne är innanför skärmen
{
	if(x>0 && x<800 && y>0 && y<600)
		return true;
	return false;
}

bool OutofBounds(GolfBall &Ball,float atX,float atY)
{
	bool out=false;
	while(Ball.getX() <= 0 || Ball.getX() >= bredd*50-1 || Ball.getY()<=0 || Ball.getY() >= hojd*50-1) // sätter den till kanten
	{
		//boll.x -=atX;
		Ball.setX(Ball.getX() - atX);
		//boll.y -=atY;
		Ball.setY(Ball.getY() - atY);
		out=true;
	}
		
	if(out==true)	//gör så att den får 2 extra värden
	{
		int bx=(int)Ball.getX()/50 , by=(int)Ball.getY()/50;		

		while(( yta[bx][by]%50==2) || (yta[bx][by]%50>=4 && yta[bx][by]%50<=8))
		{
			//boll.x -=atX;
			Ball.setX(Ball.getX() - atX);
			//boll.y -=atY;
			Ball.setY(Ball.getY() - atY);

			bx=(int)Ball.getX()/50;
			by=(int)Ball.getY()/50;
		}

		//boll.x -=atX*2;
		Ball.setX(Ball.getX() - (atX*2));
		//boll.y -=atY*2;
		Ball.setY(Ball.getY() - (atY*2));
		
		return false;
	}
	return true;
}

bool InTerrain(IsPlaying &p)
{

		int bx=(int)p.ball.x/50 , by=(int)p.ball.y/50;
		if(p.ball.current_height<=0 && ( yta[bx][by]%50==2) || (yta[bx][by]%50>=4 && yta[bx][by]%50<=8)) // Kollar vart den har landat
	{
		bool cont=true;			

		for(int i=1; cont ; i++)
			for(int x=-i; x<= i && cont ; x++)
			{
				for(int y=-i; y<= i && cont ; y++)
				{
					if( (yta[Biggest(bx+x,0)][Biggest(by+y,0)]%50<4 || yta[Biggest(bx+x,0)][Biggest(by+y,0)]%50>8) && yta[Biggest(bx+x,0)][Biggest(by+y,0)]!=2)
					{
						
						if(0>(bx+x))
							p.ball.x=25;
						else
							p.ball.x=(((int)p.ball.x/50)*50)+50*x+25;

						if(0>(by+y))
							p.ball.y=25;
						else
							p.ball.y=(((int)p.ball.y/50)*50)+50*y+25;
						
						cont=false;
						p.score++;

						return true;
					}					
				}
			}
	}	
	
	return false;
}


void InGoal(IsPlaying & play)
{	
		if(abs((int)play.ball.x-((50*((int)play.ball.x/50))+20))<6 && abs(play.ball.y-((50*((int)play.ball.y/50)+38)))<6)
		{
			play.BallInHole=true;
			snd.Hole();
			SDL_Delay(200);
		}

	
}

template<class T> 
T Biggest(T ett, T tva)
{
	if(ett>tva)
		return ett;
	return tva;
}

template<class T> 
T Smallest(T ett, T tva)
{
	if(ett<tva)
		return ett;
	return tva;
}
