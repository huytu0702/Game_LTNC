#include "Threat.h"
#include <random>

threat::threat()
{

}

bool threat::init()
{
    pos_x = SCREEN_WIDTH;
    string back_path = "assets/image/penguin.png";
    if (isNULL())
    {
        if (Load(back_path.c_str(), 0.2))
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

void threat::Free()
{
    free();
}

void threat::render()
{
    Render(pos_x, pos_y, 0);
}

int threat::getPosX()
{
    return pos_x;
}

int threat::getPosY()
{
    return pos_y;
}

void threat::update()
{
    //create random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 350 - THREAT_HEIGHT);

    //
    pos_x -= 5;
    if (pos_x + THREAT_WIDTH < 0) {
        pos_x = SCREEN_WIDTH;
        pos_y = dis(gen);
    }
}