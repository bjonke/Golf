/** 
* @file Globals.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include "SDL_mixer.h"
#include "SDL.h"
#pragma once
#include "sound.h"

#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")
#pragma comment(lib,"SDL_mixer.lib")

using namespace std;

/**
* This struct will be used for holding values for drawing surfaces.
* @author RISK
* @date 2012-07-27
*/
struct Surf
{
	/**
	* This method will be used for initiating surfaces.
	* @author RISK
	* @date 2012-07-27
	*/
	Surf();

	/**
	* This method will be used for destroying surfaces.
	* @author RISK
	* @date 2012-07-27
	*/
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


extern float hojd1;
extern float bredd1;
extern int bredd;
extern int hojd;

extern Surf surf;
extern Sound snd;
extern int **yta;
extern int ***tyta;
