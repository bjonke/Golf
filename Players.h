/** 
* @file Players.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#ifndef PLAYERS
#define PLAYERS

#include "Functions.h"
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
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
		/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	Players();
	/**
	* This method will be used to pick a player.
	* @author RISK
	* @date 2012-07-27
	*/
	void PickPlayers();
};

#endif