/** 
* @file Globals.cpp
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#include "Globals.h"

float hojd1=0;
float bredd1=0;
int bredd;
int hojd;

Surf surf;

int **yta;
int ***tyta;

Surf::Surf()
{
	ScreenSurface = 0;
	ImageSurface = 0;
	GolfImageSurface = 0;
	InitPlayerSurface = 0;
	MeterSurface = 0;
	BirdSurface = 0;
	GolferSurface = 0;
	ValueSurface = 0;
	WindSurface = 0;
	FontSurface = 0;
	HighScoreSurface = 0;

	
	ScreenSurface = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE |SDL_DOUBLEBUF  );
	

	if(! ScreenSurface)
	{
		cerr << "Error: SetVideoMode failed" << endl;		
		SDL_Quit();
		
	}
	

	//image = SDL_LoadBMP("gfx/allt.bmp");
	//golfimage = SDL_LoadBMP("gfx/golfallt.bmp");
	//initPlayer = SDL_LoadBMP("gfx/introbild.bmp");
	//matare = SDL_LoadBMP("gfx/matare.bmp");	
	//bird = SDL_LoadBMP("gfx/bird.bmp");
	//golfer = SDL_LoadBMP("gfx/golfer.bmp");
	//varde = SDL_LoadBMP("gfx/varde.bmp");
	//vind = SDL_LoadBMP("gfx/vind.bmp");

	ImageSurface = SDL_LoadBMP("gfx/allt.bmp");
	GolfImageSurface = SDL_LoadBMP("gfx/golfallt.bmp");
	InitPlayerSurface = SDL_LoadBMP("gfx/introbild.bmp");
	MeterSurface = SDL_LoadBMP("gfx/matare.bmp");	
	BirdSurface = SDL_LoadBMP("gfx/bird.bmp");
	GolferSurface = SDL_LoadBMP("gfx/golfer.bmp");
	ValueSurface = SDL_LoadBMP("gfx/varde.bmp");
	WindSurface = SDL_LoadBMP("gfx/vind.bmp");
	
	SDL_Surface *temp = SDL_LoadBMP("gfx/font.bmp");
	surf.FontSurface = SDL_ConvertSurface(temp, surf.ScreenSurface->format, SDL_SWSURFACE);
	SDL_FreeSurface(temp);

	/*
	if(!image || !golfimage || !initPlayer || !matare || !bird || !golfer || !varde || !vind)
	{
		cerr << "Error";		
		SDL_Quit();
	}*/
}

Surf::~Surf()
{
	SDL_FreeSurface(ImageSurface);
	SDL_FreeSurface(GolfImageSurface);
	SDL_FreeSurface(InitPlayerSurface);
	SDL_FreeSurface(MeterSurface);
	SDL_FreeSurface(BirdSurface);
	SDL_FreeSurface(GolferSurface);
	SDL_FreeSurface(ValueSurface);
	SDL_FreeSurface(WindSurface);
	SDL_FreeSurface(FontSurface);

// End game crashing problem here
/*
	for(int i=0; i<hojd; i++)
	{
		for(int j=0; j< bredd; j++)
		{			
			delete [] tyta[i][j];
		}
		delete [] tyta[i];
	}
*/
}

Bools::Bools()
{
	FireGolfBall = false; 	
	Value = false; 	
	SetValue = false; 	
	Done = false; 	
	FirstShot = false; 	
	PickGolfClub = false; 	
	Ground = false; 	
	Power = false; 	
	RMove = false; 	
	Done = false; 	

	//mousedown=false;
	//mouseRdown=false;
	//skjut=false;
	//value=0;
	//setvalue=true;

	//firstshot=true;
	//pickClub=true;
	//ground=true;
	//power=true;	
	//Rmove=false;
	//done=false;

}