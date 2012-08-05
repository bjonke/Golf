/** 
* @file FMain.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#ifndef FMAIN_H
#define FMAIN_H

#include "playerinput.h"
#include "Players.h"

/**
* This method will be used to pick a player.
* @author RISK
* @date 2012-07-27
*/
void PickPlayers();

/**
* This method will be used for LandSatt.
* @author RISK
* @param &isp something something
* @date 2012-07-27
*/
void LandSatt(int &isp);

/**
* This method will be used for main events.
* @author RISK
* @date 2012-07-27
*/
void MainEvents(Bools &bo,float &Rhojd,float &RBredd,int x2,int y2,GolfClub &klubb,GolfClub klubbor[],int &isp,float &value);

/**
* This method will be used for Shooting.
* @author RISK
* @date 2012-07-27
*/
void MainSkjut(bool &set,int &x2,int &y2,int &isp,GolfClub &klubb,Bools &bo, float &value,Pos &windPos,Pos &WPos);

/**
* This method will be used for Shooting.
* @author RISK
* @brief This method will be used for Shooting.
* @date 2012-07-27
*/
void FireGolfBall(bool &set,int &x2,int &y2,int &isp,GolfClub &golfclub,Bools &bo, float &value,Pos &windPos,Pos &WPos);

/**
* This method will be used for handling events.
* @author RISK
* @date 2012-07-27
*/
void EventHandler(Bools &bo,float &RHeight,float &RWidth,int x2,int y2,GolfClub &golfclub,GolfClub golfclubs[],int &isp,float &value);

#endif