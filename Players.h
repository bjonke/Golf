#ifndef PLAYERS
#define PLAYERS

#include "funktioner.h"

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

#endif