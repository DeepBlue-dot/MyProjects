#include "header.h"

void game_over()
{
    bestscore = (score > bestscore)? score : bestscore;
    score = 0;
    gravity = 0;
    i = 0, j=0;
    wall.clear();
    bird.clear();
    bird = {10,10};
    wall={{width+41,height/2}};
    poll();
}