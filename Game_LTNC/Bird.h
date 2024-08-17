#pragma once

#include "CommonFunc.h"
#include "Pipe.h"
#include "Threat.h"
#include "Item.h"

using namespace std;

class bird:gTexture
{
public:
    bool init();

    void render();

    void Free();

    void updateFrame();

    void resetTime()
    {
        time = 0;
    }

    void fall();

    void update(int pipeWidth, int pipeHeight);

    void updateThreat(int x, int y);

    void enableShield();

    bool isInvincible();

    SDL_Rect getRect();

    bool getInvicible();

    int getPosBirdX();

    int getPosBirdY();

    void renderShield();

    bool updateCollect(int x, int y);
private:
    string path = "";
    int angle = 0;
    int time, x0;
    int ahead = 0;
    position posBird;
    int currentFrame;
    threat t;
    bool invincible;
    Uint32 shieldStartTime;
    gTexture shield;
};