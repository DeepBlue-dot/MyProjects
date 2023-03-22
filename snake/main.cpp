
#include "header.h"

int hieght = 35, width = 100, length = 10,p =0, speed = 10, score=0, bestscore, run =0;
bool apple_= true , not_pause = false;
char direction = 'r';

vector<vector<int>> coo = {{10,10}};
vector<int> apple_xy ={-1,-1};




int main()
{
    thread th1(input,ref(direction), ref(not_pause), ref(score), ref(run));
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

    }while (true);
     
}








