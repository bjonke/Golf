#pragma once
#include "Globals.h"

// Replacement class for the golf_club struct
class GolfClub
{
public:
	
	GolfClub(){};
	GolfClub(float IHeight,float iLength){ mHeight = IHeight, mLength=iLength; };	
	~GolfClub(){};
private:
	float mHeight;
	float mLength;

};
