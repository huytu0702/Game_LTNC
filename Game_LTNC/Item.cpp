﻿#include "item.h"

bool Item::init()
{
    posItem.getPos(650, rand() % (SCREEN_HEIGHT - LAND_HEIGHT - 50));
    bird b;
    /*if (!b.getInvicible())
    {
        posItem.x = 60;
        posItem.y = 0;
    }*/
    active = true;
    std::string item_path = "assets/image/shield.png";  

    return Load(item_path.c_str(), 0.15);
}

void Item::Free()
{
    free();
}

void Item::render()
{
    
    if (active)
    {
        Render(posItem.x, posItem.y);
    }
}

void Item::update()
{
    posItem.x -= 2;
    //if (score%30 == 0) posItem.y = -120;
}

bool Item::checkCollision(SDL_Rect birdRect)
{
    if (active)
    {
        SDL_Rect itemRect = { posItem.x, posItem.y, getWidth(), getHeight() };
        if (SDL_HasIntersection(&birdRect, &itemRect))
        {
            active = false;  
            return true;
        }
    }
    return false;
}
