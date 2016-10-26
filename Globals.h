#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

// Should be removed as it isnt used
#include "SDL_mixer.h"

#include "SDL.h"

// Remove this to
#pragma once
#include "sound.h"

// useful for not needing to add the libs reference into the compiler config
#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")
#pragma comment(lib,"SDL_mixer.lib")

// should be replaced with the specific namespaces used as includes
using namespace std;

// Replacement for struct Surf
class DrawingSurface
{
public:
	
	// Replacement for each individual Surface object
	std::map <string, SDL_Surface*> ImageSurface;
	
	SDL_Surface* ScreenSurface;
	SDL_Surface* ImageSurface;
	SDL_Surface* GolfImageSurface;
	SDL_Surface* InitPlayerSurface;
	SDL_Surface* MeterSurface;
	SDL_Surface* BirdSurface;
	SDL_Surface* GolferSurface;
	SDL_Surface* ValueSurface;
	SDL_Surface* WindSurface;
	SDL_Surface* FontSurface;
	SDL_Surface* HighScoreSurface;

	DrawingSurface(){ std::cout << "DrawingSurface initialize..." << std::endl; };
	~DrawingSurface(){ std::cout << "DrawingSurface destruction..." << std::endl; };
};

struct Bools
{
	bool FireGolfBall;
	float Value;
	bool SetValue;
	bool Done;
	bool FirstShot;
	bool PickGolfClub;
	bool Ground;
	bool Power;
	bool RMove;
	bool MouseRightDown;
	bool MouseLeftDown;
	bool MouseDown;
	
	//bool mousedown;
	//bool mouseRdown;
	//bool skjut;
	//float value;
	//bool setvalue;
	//bool done; 	

	//bool firstshot;
	//bool pickClub;
	//bool ground;
	//bool power;
	//bool Rmove;

	Bools();
};

// Replacing the struct variables in Bools
extern bool FireGolfBall;
extern float Value;
extern bool SetValue;
extern bool FirstShot;
extern bool PIckGolfClub;
extern bool Ground;
extern bool Power;
extern bool RMove;
extern bool MouseRightDown;
extern bool MouseLeftDown;
extern bool MouseDown;

// Replace all these with something useful
extern float hojd1;
extern float bredd1;
extern int bredd;
extern int hojd;

extern Surf surf;
extern Sound snd;
extern int **yta;
extern int ***tyta;
