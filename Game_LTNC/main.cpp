#include "Game.h"
#include "CommonFunc.h"
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>
using namespace std;

int main(int argc, char* argv[]) {
	game g;
	g.renderBackground();
	g.display();
	SDL_Delay(2000);
	return 0;
}