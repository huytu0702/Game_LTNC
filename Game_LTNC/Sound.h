#pragma once


#include <SDL_mixer.h>
#include <string>
#include "CommonFunc.h"

using namespace std;

class sound:gTexture
{
public:
    bool init();

    void Free();

    void playBreath();

    void playHit();

    void renderSound();

    bool checkSound();

private:
    Mix_Chunk* breath = NULL;
    Mix_Chunk* hit = NULL;
    Mix_Chunk* drop = NULL;
    SDL_Rect Mute;
    SDL_Rect Active;
    const short int POS_X = 107;
    const short int POS_Y = 300;
    bool isPlay = 0;
};
