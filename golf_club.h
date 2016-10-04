/** 
* @file golf_club.h 
* @brief 
*
* @author demo
*
* @date 2012-07-27
*/

#pragma once
#include "Globals.h"

// Replacement class for the golf_club struct
class GolfClub
{
public:
	
	// What are these values for?
	float height;
	float length;
	
	GolfClub(){};
	GolfClub(float height,float length){ this->height = height, this->length=length; };	
	~GolfClub(){};
};

/**
* This method will be used for sound.
* @author RISK
* @date 2012-07-27
*/
struct golf_club
{
	float height;
	float length;

	golf_club(){}
	golf_club(float height,float length){this->height = height, this->length=length;}	
};

