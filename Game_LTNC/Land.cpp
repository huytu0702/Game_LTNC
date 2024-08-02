#include "land.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

bool land::init()
{
    pLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT);
    string back_path = "assets/image/land.png";
    if (isNULL())
    {
        if (Load(back_path.c_str(), 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void land::render()
{
    if (pLand.x > 0)
    {
        Render(pLand.x, pLand.y);
    }
    else if (pLand.x > -SCREEN_WIDTH && pLand.x <= 0)
    {
        Render(pLand.x, pLand.y);
        Render(pLand.x + SCREEN_WIDTH, pLand.y, 0, NULL);
    }
    else
    {
        pLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT);
        Render(pLand.x, pLand.y);
    }
}

void land::update()
{
    if (score >= 0 && score <= 20)
    {
        pLand.x -= 2;
    }
    else if (score <= 50)
    {
        pLand.x -= 3;
    }
    else pLand.x -= 4;
}

void land::Free()
{
    free();
}