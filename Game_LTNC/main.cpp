#include "Game.h"
#include "CommonFunc.h"
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>
using namespace std;

const int FPS = 60;
const int frameDelay = 1000 / FPS;


int main(int argc, char* argv[]) {
	Uint32 frameStart;
	int frameTime;
    game g;
    while (!g.isQuit())
    {
        frameStart = SDL_GetTicks();
        g.renderBackground();
        g.pipe.render();
        g.land.render();
        g.bird.render();
        g.land.update();
        g.pipe.update();
        g.bird.updateFrame();
        g.display();

        //Limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
	return 0;
}