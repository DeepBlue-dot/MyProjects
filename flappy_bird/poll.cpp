#include "header.h"

void poll()
{
    do
    {
        space_index = rand()%(height-6);
    } while (space_index<2);
    system("clear");
    for (size_t i = 0; i < 4; i++)
    {
        wall.push_back({wall[i][0]+41,space_index});
    }
    last = wall.size()-1;
}
