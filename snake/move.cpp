#include "header.h"

void move(char &direction, vector<vector<int>> &coo)
{
    switch (direction)
    {
        case 'u':
            coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]-1});
            coo.erase(coo.begin());
            break;
        case 'd':
            coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]+1});
            coo.erase(coo.begin());
            break;
        case 'r':
            coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
            coo.erase(coo.begin());
            break;
        case 'l':
            coo.push_back({coo[coo.size()-1][0]-1,coo[coo.size()-1][1]});
            coo.erase(coo.begin());
            break;
        default:
            break;
    }
    
}