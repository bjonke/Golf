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

struct Players
{
	bool tournament;
	int players,playeractivated;
    int finished_hole;
	bool picked;
	bool finished;
	
	char names[4][30];//={{'\0'},{'\0'},{'\0'},{'\0'}};
	int nameplace[4];
	int selectMap;

	Players();
	void PickPlayers();
};

#endif