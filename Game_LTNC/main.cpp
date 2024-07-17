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
	bool quit = false;
	while (quit == false)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			g.renderBackground();
			g.land.render();
			g.pipe.render();
			g.display();
			if (event.type == SDL_QUIT) quit = true;
		}
		 
	}
	return 0;
}