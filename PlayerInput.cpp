#include "playerinput.h"
//#include <string>
//#include <iostream>
//using namespace std;

//extern SDL_Surface* screen;
//extern float bredd1,hojd1;

#define PITCH (DSurface.ScreenSurface->pitch/4)

// Drawing text character on screen, this should be replaced with SDL Font code
void drawcharacter(int x, int y, int character)
{	
  //if (character == 32)
  //  return;
  
  character -= 33; // our font does not have the first 33 characters.

  // Lock surface if needed
  if (SDL_MUSTLOCK(DSurface.FontSurface))
	  if (SDL_LockSurface(DSurface.FontSurface) < 0) 
      return;

  int i, j;
  for (i = 0; i < DSurface.FontSurface->w; i++)
  {
    int screenofs = x + (y + i) * PITCH;
	int charofs = (i + character * DSurface.FontSurface->w) * (DSurface.FontSurface->pitch / 4);
	for (j = 0; j < DSurface.FontSurface->w; j++)
    {
		((unsigned int*)DSurface.ScreenSurface->pixels)[screenofs] = 
			((unsigned int*)DSurface.FontSurface->pixels)[charofs];
      screenofs++;
      charofs++;
    }
  }

  // Unlock if needed
  if (SDL_MUSTLOCK(DSurface.FontSurface)) 
		SDL_UnlockSurface(DSurface.FontSurface);
}

// Also related to BMP text drawing and should be replaced
void drawstring(int x, int y, char *s)
{		
  while (*s != 0)
  {
    drawcharacter(x, y, *s);
    s++;
	x += DSurface.FontSurface->w;
  }
}

bool Events(SDL_Surface *img,Players &pl)
{
	int x,y;
	bool start=false;
	int tx=419,ty=448,plus=37;
	SDL_Event event;

	SDL_GetMouseState(&x,&y);

	while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_MOUSEBUTTONUP:
				if(event.button.button == SDL_BUTTON_LEFT)
				{					
					if(x>102 && x< 328 && y>25 && y<241)
					{
						pl.tournament=false;
					}
					else if(x>398 && x< 626 && y>25 && y<241)
					{
						pl.tournament=true;
					}
					else if(x>438 && y>492 && x<568 && y< 552)
					{
						for(int i=0; i< pl.players ; i++)
						{
							if(pl.names[i][0]=='\0')
							{
								start=false;
								break;
							}
							else
							{
								start=true;
							}
						}	
					}
					else if(x>2 && x<68 && y>49 && y<115)
					{
						int temp=(68-2)/3;						
						pl.selectMap=(x-2)/temp+1+3*((y-49)/temp);
					}
					else if(x>54 && x<87)
					{	
						if(y>tx && y<ty)
						{
							pl.players=1;
						}
						else if(y>tx+plus && y<ty+plus)
						{
							pl.players=2;
						}
						else if(y>tx+plus*2 && y<ty+plus*2)
						{
							pl.players=3;
						}
						else if(y>tx+plus*3 && y<ty+plus*3)
						{
							pl.players=4;
						}

						pl.playeractivated=0;
					}
					else if(x>101 && x<435)
					{
						pl.playeractivated=0;

						if(y>tx && y<ty)
						{
							pl.playeractivated=1;
						}
						else if(y>tx+plus && y<ty+plus && pl.players>1)
						{
							pl.playeractivated=2;
						}
						else if(y>tx+plus*2 && y<ty+plus*2 && pl.players>2)
						{
							pl.playeractivated=3;
						}
						else if(y>tx+plus*3 && y<ty+plus*3 && pl.players>3)
						{
							pl.playeractivated=4;
						}
					}					
					else
					{
						pl.playeractivated=0;
					}
				}
				break;

			case SDL_KEYUP:				
				if(pl.playeractivated>0)
				{
					int key=event.key.keysym.sym;
					if(key >= SDLK_a && key<=SDLK_z && pl.nameplace[pl.playeractivated-1]<12)
					{
						pl.names[pl.playeractivated-1][pl.nameplace[pl.playeractivated-1]]=key;
						pl.nameplace[pl.playeractivated-1]++;
						pl.names[pl.playeractivated-1][pl.nameplace[pl.playeractivated-1]]='\0';
					}
					else if(key==SDLK_BACKSPACE && pl.nameplace[pl.playeractivated-1]>0)
					{											
						pl.names[pl.playeractivated-1][pl.nameplace[pl.playeractivated-1]-1]='\0';
						pl.nameplace[pl.playeractivated-1]--;
					}
				}
				break;		
			case SDL_KEYDOWN:	
				switch(event.key.keysym.sym)
				{
				// Remove this bool crap
				case SDLK_ESCAPE:
					extern Bools bo;
					bo.Done=true;
					start=true;
					
				}
				break;
			}
			break;
	}
	drawstring(104,426,pl.names[0]);
	drawstring(104,426+plus,pl.names[1]);
	drawstring(104,426+plus*2,pl.names[2]);
	drawstring(104,426+plus*3,pl.names[3]);

	for(int i=4; i>pl.players; i--)
	{
		DrawIMGAlpha(img,100,419+plus*(i-1),261,29,100,600,150,true);
	}
	
	if(pl.tournament)
	{		
		for(int i=0; i<7; i++)
		{
			DrawIMGAlpha(img,103,26+31*i,228,31,367,600,60,true);
		}
	}
	else
	{
		for(int i=0; i<7; i++)
		{
			DrawIMGAlpha(img,398,26+31*i,228,31,367,600,60,true);
		}
	}
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(j+1+i*3 != pl.selectMap)
			{
				DrawIMGAlpha(img,4+22*j,51+22*i,19,19,367,600,60,true);
			}
		}
	return start;
}

void BreddHojd(golf_ball_position boll)
{
	bredd1=(float)boll.x-400.0f;
	hojd1=(float)boll.y-300.f;
	if(bredd1<0)
	{
		bredd1=0;
	}
	else if(bredd1>=(bredd-16)*50)
	{
		bredd1=(bredd-16)*50-1;
	}

	if(hojd1<0)
	{
		hojd1=0;
	}
	else if(hojd1>=(hojd-12)*50)
	{
		hojd1=(hojd-12)*50-1;
	}
}

void Loadhighscore()
{
	ifstream HighscoreFile("data/highscore.txt");
	// Write the highscore data from file to variable containing both name and score of
	// higscore taker.
	// Example code for reading file
	/*
	if(HighscoreFile)
	{
		for(int i=0; i<10 && HighscoreFile.peek() !=EOF; i++)
		{
			HighscoreFile >> namn[i] >> score[i];
		}
		HighscoreFile.close();
	}
	*/
	HighsscoreFile.close();
};

// Change name to show its a draw function like DrawHighscore
void Highscore(SDL_Surface* start,IsPlaying isp[],Players &play)
{
	// Load a background for highscore list
	// Doing some sort of sorting on the highscore takers, should be moved or removed	
	if(play.finished)
	{
		for(int i=0; i<play.players; ++i)
		{		
			strcpy(namn[10],play.names[i]);
			score[10]= isp[i].score;
			bool finished_sorting=false;

			for(int j=9; j>=0 && !finished_sorting ; --j)
			{
				if(score[j] > score[j+1])
				{
					char temp[20];
					strcpy(temp,namn[j]);
					strcpy(namn[j],namn[j+1]);
					strcpy(namn[j+1],temp);

					swap(score[j],score[j+1]);
				}
				else
                		{
					finished_sorting=true;
                		}
			}
		}
	}

	int x,y;
	bool HighscoreRendering = true;

	while(HighscoreRendering)
	{
		SDL_GetMouseState(&x,&y);
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_MOUSEBUTTONUP)
			{
				if(x>338 && y>492 && x<468 && y< 552)
				{
					HighscoreRendering = false;
				}
			}
		}
		
		SDL_PixelFormat *fmt;
		fmt=DSurface.ScreenSurface->format;
		SDL_FillRect(DSurface.ScreenSurface,0,SDL_MapRGB(fmt,0,0,0));
		DrawIMGAlpha(start,337,491,133,64,437,491,255,true);
		DrawIMGAlpha(DSurface.HighScoreSurface,200,40,420,41,0,0,0,false);
		
		// Drawing the highscore text, should be replaced with something better
		char chScore[20];
		for(int i=0; i < 10; ++i)
		{			
			itoa(score[i],chScore,10);
			drawstring(260,110+30*i,namn[i]);
			drawstring(460,110+30*i,chScore);
		}

		SDL_Flip(Dsurface.ScreenSurface);
	}

	// Writing the highscore back to file sorted, this is completely unecessary if you sort
	// the highscore taker before writing them to file in a SaveHighScoreToFile function
	/*
	ofstream offil("highscore.txt");
	for(int i=0; i<10; i++)
	{
		offil << namn[i] << " " << score[i] << endl;
	}
	offil.close();
	*/
	SDL_FreeSurface(DSurface.HighScoreSurface);
}

void EscMeny(SDL_Surface *init, Bools &bo, Players &players, IsPlaying isplaying[])
{
	SDL_ShowCursor(SDL_ENABLE);
	SDL_Surface *img = SDL_LoadBMP("gfx/escmeny.bmp");

	bool done=false;
	SDL_Event event;
	int y1=50;
	int x,y;
	while(!done)
	{
		DrawIMGAlpha(img,269,175,262,251,0,0,0,false);		
			SDL_GetMouseState(&x,&y);
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_MOUSEBUTTONUP)
			{
				if(x>331 && y>208 && x<457 && y< 243) // Continue
				{
					done=true;
				}				
				else if(x>331 && y>208+y1 && x<457 && y< 243+y1) //New Game
				{
					done=true;
					for(int i=0; i<4; i++)
					{
						//players= Players();
						isplaying[i].BallInHole=false;
					}
					players= Players();
				}

				else if(x>331 && y>208+y1*2 && x<457 && y< 243+y1*2) //HighScore
				{
					done=true;
					Highscore(init,isplaying,players);
					
				}

				else if(x>331 && y+y1*3 >208 && x<457 && y< 243+y1*3) //Exit
				{
					done=true;
					bo.Done=true;
					
				}
			}	
		}
		SDL_Flip(surf.ScreenSurface);		
	}
	SDL_FreeSurface(img);
	SDL_ShowCursor(SDL_DISABLE);
}
