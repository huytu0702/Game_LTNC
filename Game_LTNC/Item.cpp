#include "item.h"

bool Item::init()
{
    posItem.getPos(rand() % (SCREEN_WIDTH - 50), rand() % (SCREEN_HEIGHT - LAND_HEIGHT - 50));  
    active = true;
    std::string item_path = "assets/image/shield.png";  

    return Load(item_path.c_str(), 0.2);
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
    posItem.y++;
    if (posItem.y >= 420) posItem.y = 0;
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
