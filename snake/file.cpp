#include "header.h"

void file(int &bs, int &s)
{
    ifstream fin (".best_score.txt");
    if(fin.is_open())
    {
        fin >> bs;
    }
    else
    {
        ofstream fout (".best_score.txt");
        fout << 0;
        bs = 0;
    }
    ofstream fout (".best_score.txt");
    if (s > bs)
    {
        fout << s;
        bs = s;
    }
    else
    {
        fout << bs;
    }

}