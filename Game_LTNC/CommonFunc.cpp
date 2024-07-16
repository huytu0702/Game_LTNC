#include <iostream>
#include "CommonFunc.h"

using namespace std;

SDL_Window* gTexture::gWindow = NULL;
SDL_Renderer* gTexture::gRenderer = NULL;
SDL_Event gTexture::event;

bool gTexture::quit = false;

gTexture::gTexture() {
	Texture = NULL;
}

gTexture::~gTexture() {

}

void gTexture::free()
{
	if (Texture != NULL)
	{
		SDL_DestroyTexture(Texture);
		Texture = NULL;
		width = 0;
		height = 0;
	}
}

bool gTexture::Load(string path, double scale) 
{
	free();

	SDL_Surface* loadSurface = IMG_Load(path.c_str());

	if (!loadSurface)
	{
		cout << "Error: Can't load IMG: " << path.c_str();
	}
	else
	{
		SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		Texture = SDL_CreateTextureFromSurface(gRenderer, loadSurface);

		if (!Texture)
		{
			cout << "Error: Can't load texture";
		}
		else
		{
			width = (loadSurface->w) * scale;
			height = (loadSurface->h) * scale;
		}

		SDL_FreeSurface(loadSurface);
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	return Texture != NULL;
}

void gTexture::Render(int x, int y, int angle, SDL_Rect* clip, SDL_RendererFlip flip)
{
	SDL_Rect rect = { x, y, width, height };

	if (clip != NULL)
	{
		rect.w = clip->w;
		rect.h = clip->h;
	}

	SDL_RenderCopyEx(gRenderer, Texture, clip, &rect, angle, NULL, flip);
}


bool gTexture::isNULL()
{
	if (Texture == NULL) return true;
	return false;
}

int gTexture::getWidth()
{
	return width;
}

int gTexture::getHeight()
{
	return height;
}