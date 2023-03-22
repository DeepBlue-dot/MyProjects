#include "header.h"

void apple(bool &apple_, vector<int> &apple_xy, int &width, int &hieght, vector<vector<int>> &coo)
{
    if(apple_)
    {
        bool loop = true;
        while (loop)
        {
            apple_xy[0] = rand() % (width);
            apple_xy[1] = rand() % (hieght);
            for (vector e : coo)
            {
                if(e[0] == apple_xy[0] && e[1] == apple_xy[1])
                {
                    loop = true;
                    break;
                }
                else
                {
                    if(0 < apple_xy[0]  && apple_xy[0]  < width-1 && 0 < apple_xy[1]  && apple_xy[1] < hieght-1)
                    {
                        loop = false;
                    }
                }
            }
        }
        apple_ = false;
    }
        
}

