#include <iostream>
#include "Bird.h"


bool bird::init()
{
    string bird_path = "assets/image/bird2.png";
    posBird.getPos(140, SCREEN_HEIGHT / 2 - 50);
    ahead = 0;
    angle = 0;
    if (isNULL())
    {
        if (Load(bird_path.c_str(), 0.75))
        {
            /*gSpriteClips[0].x = 0;
            gSpriteClips[0].y = 0;
            gSpriteClips[0].w = 60;
            gSpriteClips[0].h = 40;

            gSpriteClips[1].x = 60;
            gSpriteClips[1].y = 0;
            gSpriteClips[1].w = 60;
            gSpriteClips[1].h = 40;

            gSpriteClips[2].x = 120;
            gSpriteClips[2].y = 0;
            gSpriteClips[2].w = 60;
            gSpriteClips[2].h = 40;

            currentFrame = 0; */
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
    /*SDL_Rect* currentClip = &gSpriteClips[currentFrame];
    Render(posBird.x, posBird.y, angle, currentClip);*/
    Render(posBird.x, posBird.y, angle);
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

        if ((posBird.x + getWidth() > posPipe[ahead].x + 5) && (posBird.x + 5 < posPipe[ahead].x + pipeWidth) &&
            (posBird.y + 5 < posPipe[ahead].y + pipeHeight || posBird.y + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5))
        {
            die = true;
        }
        else if (posBird.x > posPipe[ahead].x + pipeWidth)
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
    //if (x == posBird.x + getWidth()) die = true;
}