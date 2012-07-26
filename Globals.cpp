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
	
	screen = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE |SDL_DOUBLEBUF  );
	

	if(! screen)
	{
		cerr << "Error: SetVideoMode failed" << endl;		
		SDL_Quit();
		
	}
	

	image = SDL_LoadBMP("allt.bmp");
	golfimage = SDL_LoadBMP("golfallt.bmp");
	initPlayer = SDL_LoadBMP("introbild.bmp");
	matare = SDL_LoadBMP("matare.bmp");	
	bird = SDL_LoadBMP("bird.bmp");
	golfer = SDL_LoadBMP("golfer.bmp");
	varde = SDL_LoadBMP("varde.bmp");
	vind = SDL_LoadBMP("vind.bmp");
	
	SDL_Surface *temp = SDL_LoadBMP("font.bmp");
	surf.gFont = SDL_ConvertSurface(temp, surf.screen->format, SDL_SWSURFACE);
	SDL_FreeSurface(temp);


	if(!image || !golfimage || !initPlayer || !matare || !bird || !golfer || !varde || !vind)
	{
		cerr << "Error";		
		SDL_Quit();
	}
}

Surf::~Surf()
{
	SDL_FreeSurface(image);
	SDL_FreeSurface(golfimage);
	SDL_FreeSurface(initPlayer);
	SDL_FreeSurface(matare);
	SDL_FreeSurface(bird);
	SDL_FreeSurface(golfer);
	SDL_FreeSurface(varde);
	SDL_FreeSurface(vind);
	SDL_FreeSurface(gFont);

	for(int i=0; i<9; i++)
	{
		for(int j=0; j< bredd; j++)
		{			
			delete [] tyta[i][j];
		}
		delete [] tyta[i];
	}


}

Bools::Bools()
{
	mousedown=false;
	mouseRdown=false;
	skjut=false;
	value=0;
	setvalue=true;

	firstshot=true;
	pickClub=true;
	ground=true;
	power=true;	
	Rmove=false;
	done = false; 	
}