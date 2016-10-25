#pragma once
#include "Globals.h"

#define PITCH (surf.ScreenSurface->pitch/4)

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

/*
struct golf_ball_position
{
	Pos Position;
	//float x;
	//float y;
	float height;
	float distance;
	float current_height;
	golf_ball_position() : current_height(0) {}
};
*/

class GolfBall
{
public:
	float x,y;
	float height;
	float distance;
	float currentHeight;
	GolfBall() : currentHeight(0.0f) , x(0.0f) , y(0.0f) , distance(0.0f), height(0.0f) {};
	
	float getHeight() { return height; };
	float getX() { return x; };
	float getY() { return y; };
	float getDistance() { return distance; };
	float getCurrentHeight() { return currentHeight; };
	
	float setHeight(float iHeight ) { height = iHeight; };
	float setX( float iX ) { x = iX; };
	float setY( float iY ) { y= iY; };
	float setDistance( float iDistance ) { distance = iDistance; };
	float setCurrentHeight( float iCurrentHeight ) { currentHeight = iCurrentHeight; };
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

void hitBoll(GolfClub klubba,golf_ball_position &boll);
// Old function with golf_ball_position replaced
//bool Skjut(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);

bool Skjut(IsPlaying &play, GolfBall &Ball ,Pos &Windpos,float &atX,float &atY,bool &ground);

Direction CompPosX(float bredd,float positiong);
Direction CompPosY(float hojd,float positiong);
bool CheckXY(float X,float Y);
// Old function with golf_ball_position replaced
//bool OutofBounds(golf_ball_position &boll,float tempX,float tempY);

bool OutofBounds(GolfBall &Ball,float tempX,float tempY);

bool InTerrain(IsPlaying &p);
void InGoal(IsPlaying & play);

// Old Function where golf_ball_position replaced
//void HitBall(GolfClub klubba,golf_ball_position &boll);

void HitBall(GolfClub klubba,GolfBall &Ball);

// Old function where golf_ball_position replaced
//bool Fire(IsPlaying &play, golf_ball_position &boll,Pos &Windpos,float &atX,float &atY,bool &ground);

bool Fire(IsPlaying &play, GolfBall &Ball, Pos &Windpos,float &atX,float &atY,bool &ground);
