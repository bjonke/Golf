/** 
* @file sound.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include "SDL_mixer.h"
#include "SDL.h"

#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")
#pragma comment(lib,"SDL_mixer.lib")

using namespace std;

/**
* This class will be used for sound.
* @author RISK
* @date 2012-07-27
*/
class Sound
{
public:
	Sound();
	~Sound();
	/**
	* This method will be used for sound.
	* @author RISK
	* @param file What sound file to load
	* @date 2012-07-27
	*/
	const void Load(std::string file);
	/**
	* This method will be used for sound.
	* @author RISK
	* @param soundeffect The soundeffect to use
	* @date 2012-07-27
	*/
	const void Add(Mix_Chunk* soundeffect);
	/**
	* This method will be used for sound.
	* @author RISK
	* @param id What player id to use
	* @date 2012-07-27
	*/
	const void Play(int id);
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	const void Three();
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	const void Water();
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	const void Hole();
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	const void Putter();
	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
	const void Driver();

private:
	vector<Mix_Chunk> VChunk;
	Mix_Chunk *three;
	Mix_Chunk *water;
	Mix_Chunk *hole;
	Mix_Chunk *putter;
	Mix_Chunk *driver;	
};

//extern Sound snd;