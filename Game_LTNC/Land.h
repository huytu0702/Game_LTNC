#pragma once

#include "CommonFunc.h"
#include <vector>

using namespace std;

class land : gTexture
{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    position pLand;
};
