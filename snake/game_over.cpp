#include "header.h"

void game_over(vector<int> &apple_xy, int &run, vector<vector<int>> &coo, char &direction, bool &not_pause, bool &apple_, int &bestscore, int &score, int &length)
{
    file(bestscore, score);
    run = 1;
    coo.clear();
    length = 10;
    coo.push_back({10,10});
    snake(length, coo); 
    direction = 'r';
    apple_=true;
    apple_xy.clear();
    apple_xy[0] = -1;
    apple_xy[1] = -1;
    not_pause = false;

}