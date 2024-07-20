#pragma once
#include "CommonFunc.h"
#include "Land.h"
#include "Pipe.h"
#include "Bird.h"

class game:gTexture
{
public:
	struct input
	{
		enum type { QUIT, PLAY, NONE, PAUSE };
		type Type;
	};
	input userInput;
	land land;
	pipe pipe;
	bird bird;

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

	void Input();

	bool isDie()
	{
		return die;
	}

	int getPipeWidth()
	{
		return pipe.width();
	}

	int getPipeHeight()
	{
		return pipe.height();
	}
};