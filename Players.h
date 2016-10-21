#ifndef PLAYERS
#define PLAYERS

#include <string>
#include "Functions.h"

// Replacement class for the Players struct
class Player
{
	public:
	Player();
	~Player();
	void PickPlayers();
	
	private:
	// Tournament member
	bool tournament;
	// Currently the active player
	bool active;
	// Name of player
	std::string name;
	// old variables
	int players;
	int playeractived;
	int finished_hole;
	bool picked;
	bool finished;
	char names[4][30];
	int nameplace[4];
	int selectMap;
};

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
