#include "header.h"

void move()
{
    (gravity < 3)? gravity+=0.18: gravity=2;
    bird[1]+=gravity;
    bird[1] = (bird[1]<height-1)?  bird[1]: height-2;

    for (size_t m = 0; m < wall.size(); m++)
    {
        if(wall[m][0] >-11)
            wall[m][0]--;
        else
        {
            wall[m][0]=wall[last][0]+41; 
            last=m;
            do
            {
                space_index = rand()%(height-6);
            } while (space_index<2);
            wall[m][1]= space_index;
        }  
    }         
}
