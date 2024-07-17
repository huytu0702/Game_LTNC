#pragma once

#include "CommonFunc.h"
#include <iostream>
#include <vector>

using namespace std;

extern vector<position> posPipe;

class pipe:gTexture
{
public:

    int width() { return getWidth(); }

    int height() { return getHeight(); }

    bool init();

    void render();

    void update();

    void Free();
private:
    const int randMin = -343;
    const int randMax = SCREEN_HEIGHT - LAND_HEIGHT - 373 - PIPE_DISTANCE - 30;
};