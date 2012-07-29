/** 
* @file funktioner.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#pragma once
#include "skjut.h"
//extern int bredd;
//extern int hojd;

//struct Pos;
//struct Bollpos;
/**
* This method will be used for creating random wind values.
* @author RISK
* @date 2012-07-27
*/
void Windrandom(float &x,float &y,float &max);

/**
* This method will be used for using the wind values.
* @author RISK
* @date 2012-07-27
*/
void UseWind(bool &startMove, Pos &boll,Pos &WPos);

/**
* This method will be used for drawing image with alpha values.
* @author RISK
* @date 2012-07-27
*/
void DrawIMGAlpha(SDL_Surface *img,int x, int y, int w, int h, int x2, int y2, int trans, bool alpha_on);

/**
* This method will be used for drawing lines.
* @author RISK
* @date 2012-07-27
*/
void DrawLine(float startX,float startY,float stopX,float stopY);

/**
* This method will be used for drawing circles.
* @author RISK
* @date 2012-07-27
*/
void drawcircle(int x, int y, int r, int c);

/**
* This method will be used for manipulating the ball position.
* @author RISK
* @date 2012-07-27
*/
void Matare(golf_ball_position &boll);

/**
* This method will be used for calculating the power for striking the golf ball.
* @author RISK
* @date 2012-07-27
*/
float Power(bool &first);

/**
* This method will be used for viewing the power value.
* @author RISK
* @date 2012-07-27
*/
void ViewPower(float power);

/**
* This method will be used for viewing the wind value.
* @author RISK
* @date 2012-07-27
*/
void viewWind(Pos &WindPos,golf_ball_position &boll);

/**
* This method will be used for viewing the bird.
* @author RISK
* @date 2012-07-27
*/
void viewBird();

/**
* This method will be used for animating the player.
* @author RISK
* @date 2012-07-27
*/
void animPlayer(float value);