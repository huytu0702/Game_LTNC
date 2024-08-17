#pragma once

#include "CommonFunc.h"

class fruit :gTexture
{
public:
	bool init();
	void render();
	void update();
	void setPosition(int x, int y);
	void Free();

	int getX();
	int getY();
private:
	int currentFrame;
	SDL_Rect fruitRect;
};