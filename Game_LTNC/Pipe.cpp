﻿#include "pipe.h"
#include "stdio.h"

vector<position> posPipe;

bool pipe::init()
{
    posPipe.clear();
    for (int i = 0; i < TOTAL_PIPE; i++)
    {
        position tmp;
        tmp.getPos(SCREEN_WIDTH + i * PIPE_DISTANCE + 350, (rand() % (randMax - randMin + 1)) + randMin);
        posPipe.push_back(tmp);
    }
    if (isNULL())
    {
        if (Load("assets/image/pipe.png", 1))
        {
            return true;
        }
    }
    return false;
}

void pipe::render()
{
    for (int i = 0; i < TOTAL_PIPE; i++)
    {
        if (posPipe[i].x <= SCREEN_WIDTH && posPipe[i].x > -getWidth())
        {
            Render(posPipe[i].x, posPipe[i].y);
        }
        Render(posPipe[i].x, posPipe[i].y + getHeight() + PIPE_SPACE, 180);
    }
}

void pipe::update()
{
    if (!die)
    {
        for (int i = 0; i < TOTAL_PIPE; i++)
        {
            if (posPipe[i].x < -getWidth())
            {
                posPipe[i].y = (rand() % (randMax - randMin + 1)) + randMin;
                posPipe[i].x = posPipe[(i + TOTAL_PIPE - 1) % TOTAL_PIPE].x + PIPE_DISTANCE;
            }
            else
            {
                if (score >= 0 && score <= 10)
                {
                    posPipe[i].x -= 2;
                }
                else if (score <= 40)
                {
                    posPipe[i].x -= 3;
                }
                else posPipe[i].x -= 4;
            }
        }
    }
}

void pipe::Free()
{
    free();
}