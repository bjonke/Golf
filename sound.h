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

class Sound
{
public:
	Sound();
	~Sound();
	void Load(std::string file);
	void Add(Mix_Chunk* soundeffect);
	void Play(int id);
	void Three();
	void Water();
	void Hole();
	void Putter();
	void Driver();

private:
	vector<Mix_Chunk> VChunk;
	Mix_Chunk *three;
	Mix_Chunk *water;
	Mix_Chunk *hole;
	Mix_Chunk *putter;
	Mix_Chunk *driver;	
};

//extern Sound snd;