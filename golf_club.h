/** 
* @file golf_club.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#pragma once
#include "Globals.h"

	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
struct golf_club
{
	float height;
	float length;
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/	
	golf_club(){}
		/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	golf_club(float height,float length){this->height = height, this->length=length;}	
};

