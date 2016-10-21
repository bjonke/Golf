#pragma once
#include "skjut.h"
//extern int bredd;
//extern int hojd;

//struct Pos;
//struct Bollpos;
// Replacement for Windrandom function
void WindEffect(float &x,float &y,float &max);
// Replacement function for drawcircle function
void DrawGolfBall(int x, int y, int r, int c);

void Windrandom(float &x,float &y,float &max);
void UseWind(bool &startMove, Pos &boll,Pos &WPos);
void DrawIMGAlpha(SDL_Surface *img,int x, int y, int w, int h, int x2, int y2, int trans, bool alpha_on);
void DrawLine(float startX,float startY,float stopX,float stopY);

void drawcircle(int x, int y, int r, int c);
void Matare(golf_ball_position &boll);
float Power(bool &first);
void ViewPower(float power);
void viewWind(Pos &WindPos,golf_ball_position &boll);
void viewBird();
void animPlayer(float value);
