/** 
* @file Globals.h 
* @brief 
*
* @author demo
*
* @date 2012-07-27
*/

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

	DrawingSurface(){};
	~DrawingSurface(){};
};

/**
* This struct will be used for holding values for drawing surfaces.
* @author demo
* @date 2012-07-27
*/
struct Surf
{
	Surf();
	~Surf();

	//SDL_Surface* screen;
	//SDL_Surface* image;
	//SDL_Surface* golfimage;
	//SDL_Surface* initPlayer;
	//SDL_Surface* matare;
	//SDL_Surface *bird;
	//SDL_Surface *golfer;
	//SDL_Surface* varde;
	//SDL_Surface* vind;
	//SDL_Surface *gFont;
	//SDL_Surface *hscore;

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
};

/**
* This struct will be used for keeping track of booleans.
* @author RISK
* @date 2012-07-27
*/
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

	/**
	* This method will be used for initiating the struct.
	* @author RISK
	* @date 2012-07-27
	*/
	Bools();
};

// Replace all these with something useful
extern float hojd1;
extern float bredd1;
extern int bredd;
extern int hojd;

extern Surf surf;
extern Sound snd;
extern int **yta;
extern int ***tyta;
