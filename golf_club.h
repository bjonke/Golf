#pragma once
#include "Globals.h"

struct golf_club
{
	float height;
	float length;
	
	golf_club(){}
	golf_club(float height,float length){this->height = height, this->length=length;}	
};