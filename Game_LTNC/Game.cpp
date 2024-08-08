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
	bird.init();
	threat.init();
	sound.init();
}

game::~game()
{
	bird.Free();
	pipe.Free();
	land.Free();
	threat.Free();
	sound.Free();
	free();
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

void game::Input()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			userInput.Type = input::QUIT;
			quit = true;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN || (event.type == SDL_KEYDOWN &&
			(event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0))
		{
			userInput.Type = input::PLAY;
		}
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0)
		{
			userInput.Type = input::PAUSE;
		}
	}
}

void game::resume()
{
	gTexture image;
	image.Load("assets/image/resume.png", 1);
	image.Render(SCREEN_WIDTH - 50, 20);
	image.free();
}

void game::pause()
{
	gTexture image;
	image.Load("assets/image/pause.png", 1);
	image.Render(SCREEN_WIDTH - 50, 20);
	image.free();
}

void game::renderPauseTab()
{
	gTexture image;
	image.Load("assets/image/pauseTab.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 230);
	image.free();
}

void game::nextButton()
{
	gTexture image;
	image.Load("assets/image/nextRight.png", 1);
	image.Render(149, 322);
	image.Load("assets/image/nextLeft.png", 1);
	image.Render(88, 322);
	image.free();
}

void game::renderGameOver()
{
	gTexture image;
	image.Load("assets/image/gameOver.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 150);
	image.free();
}

void game::replay()
{
	gTexture image;
	image.Load("assets/image/replay.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 380);
	image.free();
}

bool game::checkReplay()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > (SCREEN_WIDTH - 100) / 2 && x < (SCREEN_WIDTH + 100) / 2 && y > 380 && y < 380 + 60)
	{
		return true;
	}
	return false;
}

void game::Restart()
{
	die = false;
	score = 0;
	bird.resetTime();
}

void game::renderScoreSmall()
{
	string s = to_string(score);
	signed char len = s.length();
	gTexture image;

	for (signed char i = len - 1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("assets/number/small/1.png", 0.75);
		}
		else if (number == 2)
		{
			image.Load("assets/number/small/2.png", 0.75);
		}
		else if (number == 3)
		{
			image.Load("assets/number/small/3.png", 0.75);
		}
		else if (number == 4)
		{
			image.Load("assets/number/small/4.png", 0.75);
		}
		else if (number == 5)
		{
			image.Load("assets/number/small/5.png", 0.75);
		}
		else if (number == 6)
		{
			image.Load("assets/number/small/6.png", 0.75);
		}
		else if (number == 7)
		{
			image.Load("assets/number/small/7.png", 0.75);
		}
		else if (number == 8)
		{
			image.Load("assets/number/small/8.png", 0.75);
		}
		else if (number == 9)
		{
			image.Load("assets/number/small/9.png", 0.75);
		}
		else
		{
			image.Load("assets/number/small/0.png", 0.75);
		}
		image.Render(260 - image.getWidth() * (len - i - 1) * 0.75 - 5 * (len - i - 1), 268);
	}
	image.free();
}

void game::renderScoreLarge()
{
	string s = to_string(score);
	signed char len = s.length();
	gTexture image;

	for (signed char i = 0; i < len; i++)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("assets/number/large/1.png", 1);
		}
		else if (number == 2)
		{
			image.Load("assets/number/large/2.png", 1);
		}
		else if (number == 3)
		{
			image.Load("assets/number/large/3.png", 1);
		}
		else if (number == 4)
		{
			image.Load("assets/number/large/4.png", 1);
		}
		else if (number == 5)
		{
			image.Load("assets/number/large/5.png", 1);
		}
		else if (number == 6)
		{
			image.Load("assets/number/large/6.png", 1);
		}
		else if (number == 7)
		{
			image.Load("assets/number/large/7.png", 1);
		}
		else if (number == 8)
		{
			image.Load("assets/number/large/8.png", 1);
		}
		else if (number == 9)
		{
			image.Load("assets/number/large/9.png", 1);
		}
		else
		{
			image.Load("assets/number/large/0.png", 1);
		}
		image.Render((SCREEN_WIDTH - (image.getWidth() * len + (len - 1) * 10)) / 2 + (i + 20) * i, 100);
	}
	image.free();
}

void game::renderBestScore()
{
	ifstream fileIn("res/data/bestScore.txt");
	fileIn >> bestScore;
	ofstream fileOut("res/data/bestScore.txt", ios::trunc);

	if (score > bestScore)
	{
		bestScore = score;
	}
	string s = to_string(bestScore);
	signed char len = s.length();
	gTexture image;

	for (signed char i = len - 1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("assets/number/small/1.png", 0.75);
		}
		else if (number == 2)
		{
			image.Load("assets/number/small/2.png", 0.75);
		}
		else if (number == 3)
		{
			image.Load("assets/number/small/3.png", 0.75);
		}
		else if (number == 4)
		{
			image.Load("assets/number/small/4.png", 0.75);
		}
		else if (number == 5)
		{
			image.Load("assets/number/small/5.png", 0.75);
		}
		else if (number == 6)
		{
			image.Load("assets/number/small/6.png", 0.75);
		}
		else if (number == 7)
		{
			image.Load("assets/number/small/7.png", 0.75);
		}
		else if (number == 8)
		{
			image.Load("assets/number/small/8.png", 0.75);
		}
		else if (number == 9)
		{
			image.Load("assets/number/small/9.png", 0.75);
		}
		else
		{
			image.Load("assets/number/small/0.png", 0.75);
		}
		image.Render(260 - image.getWidth() * (len - i - 1) * 0.75 - 5 * (len - i - 1), 315);
	}
	image.free();

	fileOut << bestScore;
	fileIn.close();
	fileOut.close();
}

void game::renderMedal()
{
	gTexture image;

	if (score >= 0 && score <= 20)
	{
		image.Load("assets/medal/bronze.png", 0.75);
	}
	else if (score > 20 && score <= 50)
	{
		image.Load("assets/medal/silver.png", 0.75);
	}
	else if (score > 50)
	{
		image.Load("assets/medal/gold.png", 0.75);
	}
	image.Render(86, 275);

	image.free();
}

void game::renderReady()
{
	gTexture image;
	image.Load("assets/image/message.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 180);
	image.free();
}