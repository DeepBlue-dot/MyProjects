#include "header.h"

char find_char (int& w,  int& h)
{
    for (size_t i = 0; i < wall.size(); i++)
    {
        if ((w==wall[i][0] || w==wall[i][0]-10) && (h<wall[i][1] || h>wall[i][1]+5))
        {
            if((w==bird[0]-1|| w==bird[0]+1 || w==bird[0]) && h==bird[1])
            {
                file(bestscore, score);
                game_over();
                run = false;
            }
            if(wall[i][0]+1==bird[0])
                score++;
            return '|';
        }
        if(w < wall[i][0] && w>wall[i][0]-10&& (h==wall[i][1]-1|| h==wall[i][1]+6))
        {
            if(w==bird[0] && h==bird[1])
            {
                file(bestscore, score);
                game_over();
                run = false;
            }
            return '=';
        }
        
    }
    if(w==bird[0]&& h==bird[1])
    {
        return '0';
    }
    if(w==bird[0]-1&& h==bird[1])
    {
        return wing[k%2];
    }
    if(w==bird[0]+1&& h==bird[1])
    {
        return wing[(k+1)%2];
    }
    return ' ';
}
