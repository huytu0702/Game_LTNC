#pragma once
#include "CommonFunc.h"
#include "Land.h"
#include "Pipe.h"

class game:gTexture
{
public:
	land land;
	pipe pipe;


	game();
	~game();

	bool init();
	void renderBackground();
	void renderLand();
	void display();

	void clear();
	bool isQuit()
	{
		return quit;
	}
};