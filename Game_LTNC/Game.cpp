#include "Game.h"
#include <iostream>

using namespace std;

bool game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Error: Init";
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			cout << "Error: Can't load Window";
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Can't Render";
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout << "Error: " << IMG_GetError();
					success = false;
				}

				if (TTF_Init() == -1)
				{
					cout << "Error: " << TTF_GetError();
					success = false;
				}
			}
		}
	}

	return success;
}

game::game()
{
	init();
	land.init();
	pipe.init();
}

game::~game()
{
	free();
	pipe.Free();
	land.Free();
	clear();
}

void game::display()
{
	SDL_RenderPresent(gRenderer);
	SDL_RenderClear(gRenderer);
}

void game::clear()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void game::renderBackground()
{
	gTexture image;
	image.Load("assets/image/background.png", 1);
	image.Render(0, 0);
	image.free();
}