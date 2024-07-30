#pragma once
#include "CommonFunc.h"
#include "Land.h"
#include "Pipe.h"
#include "Bird.h"
#include <fstream>

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

	void resume();

	void pause();

	void renderPauseTab();

	void replay();

	bool checkReplay();

	void Restart();

	void nextButton();

	void renderGameOver();

	void renderScoreSmall();

	void renderScoreLarge();

	void renderBestScore();

private:
	int bestScore;
};