#include "header.h"

void game(vector<vector<int>> &coo, int &width, int &hieght, int &score, char &direction, vector<int> &apple_xy, bool &apple_, int &run, int &bestscore,int &length, bool &not_pause, float &speed)
{
    thread th1(input,ref(direction), ref(not_pause), ref(score), ref(run), ref(speed));
    snake(length, coo);
    srand(time(NULL));
    file(bestscore, score);
    do
    {
        if (run == 0)
        {
            if(not_pause)
            {
                print(coo, score, bestscore, hieght, width, speed, apple_xy);
                move(direction,coo);
                check(coo,width,hieght,score,direction,apple_xy,apple_,run,bestscore,length,not_pause);
                apple(apple_,apple_xy,width,hieght,coo);
                
            }
            else
            {
                print(coo, score, bestscore, hieght, width, speed, apple_xy);
                
            }
        }
        else if(run == 1)
        {
            cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
            cout << "\n\t\tGAME OVER!!\n";
            run = 2;
        }

    }while (run != 3);
}