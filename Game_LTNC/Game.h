#pragma once
#include "CommonFunc.h"

class game:gTexture
{
public:
	game();
	~game();

	bool init();
	void renderBackground();
	void display();

	void clear();
	bool isQuit()
	{
		return quit;
	}
};