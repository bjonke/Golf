#ifndef FMAIN_H
#define FMAIN_H

#include "playerinput.h"
#include "Players.h"

void PickPlayers();

void LandSatt(int &isp);
void CheckBallLanded(int &current_player);
void MainEvents(Bools &bo,float &Rhojd,float &RBredd,int x2,int y2,GolfClub &klubb,GolfClub klubbor[],int &isp,float &value);

void MainSkjut(bool &set,int &x2,int &y2,int &isp,GolfClub &klubb,Bools &bo, float &value,Pos &windPos,Pos &WPos);
void FireGolfBall(bool &set,int &x2,int &y2,int &isp,GolfClub &golfclub,Bools &bo, float &value,Pos &windPos,Pos &WPos);

void EventHandler(Bools &bo,float &RHeight,float &RWidth,int x2,int y2,GolfClub &golfclub,GolfClub golfclubs[],int &isp,float &value);

#endif
