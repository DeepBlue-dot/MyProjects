#include "header.h"

void game_over()
{
    bestscore = (score/29 > bestscore)? score/29 : bestscore;
    score = 0;
    gravity = 0;
    i = 0, j=0;
    wall.clear();
    bird.clear();
    bird = {10,10};
    wall={{width,height/2}};
}