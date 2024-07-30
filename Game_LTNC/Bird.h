#pragma once

#include "CommonFunc.h"
#include "Pipe.h"
#include "Threat.h"

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
private:
    string path = "";
    int angle = 0;
    int time, x0;
    int ahead = 0;
    position posBird;
    SDL_Rect gSpriteClips[3];
    int currentFrame;
};