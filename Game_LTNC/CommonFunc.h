#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

const int COLOR_KEY_R = 0x00;
const int COLOR_KEY_G = 0xFF;
const int COLOR_KEY_B = 0xFF;


class gTexture 
{
public:
	gTexture();
	~gTexture();

	bool Load(string path, double scale = 1);

	void Render(int x, int y, int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void free();
	bool isNULL();

	int getWidth();
	int getHeight();

	SDL_Texture* Texture;

	int width;
	int height;

	static SDL_Window* gWindow;
	static SDL_Renderer* gRenderer;
	static SDL_Event event;

	static const int SCREEN_HEIGHT = 625;
	static const int SCREEN_WIDTH = 350;
	static const int LAND_HEIGHT = 140;
	static const int PIPE_DISTANCE = 222;
	static const int TOTAL_PIPE = 4;
	static const short int PIPE_SPACE = 155;

	static bool quit;
};

class position
{
public:
	int x, y, angle, state;
	void getPos(const int x, const int y);
};