#pragma once
#include "Globals.h"

#define PITCH (surf.screen->pitch/4)

template<class T> 
T Biggest(T ett, T tva);

template<class T> 
T Smallest(T ett, T tva);

enum Direction{Up,Down,Right,Left,None};

struct Pos
{
	float x;
	float y;
};

struct golf_ball_position
{
	float x;
	float y;
	float height;
	float distance;
	float current_height;
	golf_ball_position() : current_height(0) {}
};

struct club
{
	float height;
	float distance;
	club() {}
	club(float height,float distance){this->height= height, this->distance=distance;}
};

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


void hitBoll(club klubba,golf_ball_position &boll);

bool Skjut(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);
Direction CompPosX(float bredd,float positiong);
Direction CompPosY(float hojd,float positiong);
bool CheckXY(float X,float Y);
bool OutofBounds(golf_ball_position &boll,float tempX,float tempY);
bool InTerrain(IsPlaying &p);
void InGoal(IsPlaying & play);

// RISK Functions
void HitBall(club klubba,golf_ball_position &boll);
bool Fire(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);
