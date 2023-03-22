#include "header.h"

void check(vector<vector<int>> &coo, int &width, int &hieght, int &score, char &direction, vector<int> &apple_xy, bool &apple_, int &run, int &bestscore,int &length, bool &not_pause)
{
    for (int i=0; i < coo.size(); i++)
    {
        if(coo[i][0] < 1 || coo[i][0] >= width-1 || coo[i][1] < 1 || coo[i][1] >= hieght-1)
        {
            game_over(apple_xy,run,coo,direction,not_pause,apple_,bestscore,score,length);
        }
    
        if (coo[i][0] == apple_xy[0] && coo[i][1] == apple_xy[1])
        {
            apple_ = true;
                switch (direction)
                {
                    case 'u':
                        coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]-1});
                        break;
                    case 'd':
                        coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]+1});
                        break;
                    case 'r':
                        coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
                        
                        break;
                    case 'l':
                        coo.push_back({coo[coo.size()-1][0]-1,coo[coo.size()-1][1]});
                        break;
                    default:
                        break;
                }
            score+=1;
        }
        
    }
    for(int p =0; p < coo.size(); p++)
    {
        for(int q =0; q < coo.size(); q++)
        {
            if(p != q && coo[p][0] == coo[q][0] && coo[p][1] == coo[q][1])
            {
                game_over(apple_xy,run,coo,direction,not_pause,apple_,bestscore,score,length);
            }
        }

    }
    
}