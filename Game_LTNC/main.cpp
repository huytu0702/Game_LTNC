﻿#include "Game.h"
#include "CommonFunc.h"
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main(int argc, char* argv[]) {
    Uint32 frameStart;
    int frameTime;
    game g;
    bool isMenu = 0;
    bool isPause = 0;
    bool isDark = 0;
    bool isSound = 1;
    gTexture g2;

    while (!g.isQuit())
    {
        frameStart = SDL_GetTicks();

        if (g.isDie())
        {
            if (isMenu) {
                // g.bird.updateFrame();
                g.sound.playHit();
                g.bird.render();
            }
            g.userInput.Type = game::input::NONE;
            while (g.isDie() && !g.isQuit())
            {
                g.Input();
                if (isMenu == 1 && g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isMenu = 0;
                    }
                    g.userInput.Type = game::input::NONE;
                }
                g.renderBackground();
                g.land.render();
                if (isMenu)
                {
                    //g.bird.updateFrame();
                    g.bird.render();
                    g.bird.fall();
                    g.renderGameOver();
                    g.renderScoreSmall();
                    g.renderMedal();
                    g.renderBestScore();
                    g.replay();
                }
                else
                {
                    g.pipe.init();
                    g.threat.init();
                    g.bird.init();
                    g.bird.render();
                    g.renderReady();
                    if (g.userInput.Type == game::input::PLAY)
                    {
                        g.Restart();
                        isMenu = 1;
                        g.userInput.Type = game::input::NONE;
                    }
                    g.land.update();
                }
                g.display();
            }
            g.pipe.init();
            g.threat.init();
        }
        else
        {
            g.Input();

            if (g.userInput.Type == game::input::PAUSE)
            {
                isPause = abs(1 - isPause);
                g.userInput.Type = game::input::NONE;
            }

            if (isPause == 0 && g.userInput.Type == game::input::PLAY)
            {
                if (isSound) g.sound.playBreath();
                g.bird.resetTime();
                g.userInput.Type = game::input::NONE;
            }
            g.renderBackground();
            if (g2.score > 20) g.threat.update();
            g.pipe.render();
            g.threat.render();
            g.land.render();
            //g.bird.updateFrame();
            g.bird.render();
            g.item.render();
            g.renderScoreLarge();

            if (!isPause)
            {
                g.bird.updateThreat(g.threat.getPosX(), g.threat.getPosY());
                g.bird.update(g.getPipeWidth(), g.getPipeHeight());
                g.item.update();
                g.pipe.update();
                if (g2.score > 20) g.threat.update();
                g.land.update();
                g.pause();
            }
            else
            {
                g.resume();
                g.renderPauseTab();
                g.renderScoreSmall();
                g.renderBestScore();
                g.replay();
                g.nextButton();
                g.sound.renderSound();
                if (g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isPause = 0;
                    }
                    else if (g.sound.checkSound())
                    {
                        isSound = abs(1 - isSound);
                    }

                    g.userInput.Type = game::input::NONE;
                }
            }
            g.display();
        }

        //Limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}