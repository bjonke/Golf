/** 
* @file skjut.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#pragma once
#include "Globals.h"

#define PITCH (surf.ScreenSurface->pitch/4)

template<class T> 
T Biggest(T ett, T tva);

template<class T> 
T Smallest(T ett, T tva);

enum Direction{Up,Down,Right,Left,None};

/**
* This struct will be used for Positioning.
* @author RISK
* @date 2012-07-27
*/
struct Pos
{
	float x;
	float y;
};

/**
* This struct will be used for positioning the golf ball.
* @author RISK
* @date 2012-07-27
*/
struct golf_ball_position
{
	float x;
	float y;
	float height;
	float distance;
	float current_height;
	golf_ball_position() : current_height(0) {}
};

/**
* This method will be used for the different golf clubs.
* @author RISK
* @date 2012-07-27
*/
struct club
{
	float height;
	float distance;
	club() {}
	club(float height,float distance){this->height= height, this->distance=distance;}
};

/**
* This method will be used for checking who is playing.
* @author RISK
* @date 2012-07-27
*/
struct IsPlaying
{
	int x;
	int y;
	//bool sattbollen;
	//bool landat;
	int score;
	//IsPlaying(){sattbollen=false; landat=false; score=0;}
	golf_ball_position ball;
	bool BallInHole;
	bool BallLanded;
	IsPlaying(){BallInHole=false; BallLanded=false; score=0;}

};

/**
* This method will be used for hitting the golf ball.
* @author RISK
* @date 2012-07-27
*/
void hitBoll(club klubba,golf_ball_position &boll);

/**
* This method will be used for Shooting the golf ball.
* @author RISK
* @date 2012-07-27
*/
bool Skjut(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);

/**
* This method will be used for checking the direction.
* @author RISK
* @date 2012-07-27
*/
Direction CompPosX(float bredd,float positiong);

/**
* This method will be used for checking the direction.
* @author RISK
* @date 2012-07-27
*/
Direction CompPosY(float hojd,float positiong);

/**
* This method will be used for checking XY.
* @author RISK
* @date 2012-07-27
*/
bool CheckXY(float X,float Y);

/**
* This method will be used for checking if the golf ball is out of bounds.
* @author RISK
* @date 2012-07-27
*/
bool OutofBounds(golf_ball_position &boll,float tempX,float tempY);

/**
* This method will be used for checking if the golf ball is in the terrain.
* @author RISK
* @date 2012-07-27
*/
bool InTerrain(IsPlaying &p);

/**
* This method will be used for checking if the golf ball is in the hole.
* @author RISK
* @date 2012-07-27
*/
void InGoal(IsPlaying & play);

/**
* This method will be used for hitting the ball with a specific golf club.
* @author RISK
* @date 2012-07-27
*/
void HitBall(club klubba,golf_ball_position &boll);

/**
* This method will be used for making the golf ball fly away after hitting it.
* @author RISK
* @date 2012-07-27
*/
bool Fire(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);