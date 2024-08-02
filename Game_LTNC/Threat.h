#pragma once
#pragma once

#include "CommonFunc.h"

using namespace std;

class threat:gTexture
{
public:
    bool init();

    void render();

    void Free();

    int getPosX();

    int getPosY();

    void update();

private:
    int pos_x, pos_y;
};