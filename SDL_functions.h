#include <cstdlib>
using namespace std;
#include "SDL.h" // Uint32
#include "FMain.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_DEPTH 32

int InitVideo(Uint32 flags = SDL_DOUBLEBUF | SDL_INIT_AUDIO) 
{
  // Load SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) 
  {
    fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    return false;
  }
  atexit(SDL_Quit);
 
  surf.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, flags);
  if (surf.screen == NULL) 
  {
    fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
    return false;
  }
  return true;
}