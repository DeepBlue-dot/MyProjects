#include "header.h"

void snake(int &l, vector<vector<int>> &coo)
{
    for(int i = 0; i < (l-1); i++)
    {
        coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
    }
}