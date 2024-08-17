#include <iostream>
#include "Bird.h"


bool bird::init()
{
    string bird_path = "assets/image/bird2.png";
    posBird.getPos(140, SCREEN_HEIGHT / 2 - 50);
    ahead = 0;
    angle = 0;
    string shield_path = "assets/image/shield.png";
    shield.Load(shield_path.c_str(), 0.15);
    if (isNULL())
    {
        if (Load(bird_path.c_str(), 0.75))
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

void bird::Free()
{
    free();
}

void bird::render()
{
    Render(posBird.x, posBird.y, angle);
    if (isInvincible())
    {
        renderShield();
    }
}

void bird::renderShield()
{
    shield.Render(posBird.x - 17, posBird.y - 22);  
}


void bird::updateFrame()
{
    currentFrame++;
    if (currentFrame == 2)
    {
        currentFrame = 0;
    }
}

void bird::fall()
{
    if (die && posBird.y < SCREEN_HEIGHT - LAND_HEIGHT - BIRD_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void bird::update(int pipeWidth, int pipeHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
        if (!isInvincible())
        {
            if ((posBird.x + getWidth() > posPipe[ahead].x + 5) && (posBird.x + 5 < posPipe[ahead].x + pipeWidth) &&
                (posBird.y + 5 < posPipe[ahead].y + pipeHeight || posBird.y + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5))
            {
                die = true;
            }
        }
             if (posBird.x > posPipe[ahead].x + pipeWidth)
            {
                ahead = (ahead + 1) % TOTAL_PIPE;
                score++;
            }
        

        if (posBird.y > SCREEN_HEIGHT - LAND_HEIGHT - BIRD_HEIGHT - 5 || posBird.y < -10)
        {
            die = true;
        }
    }
}

void bird::updateThreat(int x, int y)
{
    //check va cham threat
    if (!isInvincible())
    {
        if (!(posBird.x + getWidth() < x ||
            posBird.x > x + THREAT_WIDTH * 0.2 ||
            posBird.y + getHeight() < y ||
            posBird.y > y + THREAT_HEIGHT * 0.2)
            )
        {
            die = true;
        }
    }
}

void bird::enableShield()
{
    invincible = true;
    shieldStartTime = SDL_GetTicks(); 
}

bool bird::isInvincible()
{
    if (invincible && SDL_GetTicks() - shieldStartTime >= 5000)
    {
        invincible = false;  
    }
    return invincible;
}

SDL_Rect bird::getRect()
{
    SDL_Rect rect;
    rect.x = posBird.x;
    rect.y = posBird.y;
    rect.w = getWidth();  
    rect.h = getHeight();
    return rect;
}

bool bird::getInvicible() {
    return invincible;
}

int bird::getPosBirdX() {
    return posBird.x;
}

int bird::getPosBirdY() {
    return posBird.y;
}

bool bird::updateCollect(int x, int y)
{
        if (!(posBird.x + getWidth() < x ||
            posBird.x > x + 32 ||
            posBird.y + getHeight() < y ||
            posBird.y > y + 32)
            )
        {
            return true;
        }
        return false;
}