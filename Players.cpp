#include "Players.h"

Players::Players()
{
	selectMap=1;
	players=1;
	playeractivated=0;
	tournament=false;
	finished_hole = 0;
	picked=false;
	finished=false;

	for(int i=0; i<4; i++)
	{
		names[i][0]='\0';
		nameplace[i]=0;
	}
}

void Players::PickPlayers()
{
	DrawIMGAlpha(surf.InitPlayerSurface,0,0,800,600,0,0,0,false);
	/*
	players.picked=Events(surf.initPlayer,players);				
	SDL_Flip(surf.screen);	
	if(players.picked)
	{
		if(!players.tournament)
		{
			for(int i=0; i<4; i++)						
				isplaying[i].ball=boll[players.selectMap-1];
			mapnow=players.selectMap-1;
		}
		else
		{
			for(int i=0; i<4; i++)						
				isplaying[i].ball=boll[0];
			mapnow=0;
		}
		BreddHojd(isplaying[0].ball);				
		bredd=br[mapnow];
		hojd=ho[mapnow];
		yta=tyta[mapnow];
		BreddHojd(boll[mapnow]);

	}
	*/
}
