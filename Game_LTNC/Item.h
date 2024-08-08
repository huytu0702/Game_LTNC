#pragma once
#include "CommonFunc.h"
#include "Bird.h"

class Item : gTexture
{
public:
    bool init();
    void Free();
    void render();
    void update();
    bool checkCollision(SDL_Rect birdRect);  

private:
    position posItem;
    bool active;
};
