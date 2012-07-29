/** 
* @file playerinput.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#ifndef PLAYERINPUT
#define PLAYERINPUT

#include "funktioner.h"
#include "Players.h"
/*
struct Players
{
	bool tournament;
	int players,playeractivated;
	int antalsomsattden;
	bool picked;
	bool finished;
	
	char names[4][30];//={{'\0'},{'\0'},{'\0'},{'\0'}};
	int nameplace[4];
	int selectMap;
	Players();
};
*/
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
bool Events(SDL_Surface *img,Players &pl);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void drawcharacter(int x, int y, int character);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void drawstring(int x, int y, char *s);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void InitGfont();
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void BreddHojd(golf_ball_position boll);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void Highscore(SDL_Surface* start,IsPlaying isp[],Players &play);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
void EscMeny(SDL_Surface *init, Bools &bo, Players &players, IsPlaying isplaying[]);

#endif