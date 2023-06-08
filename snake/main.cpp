
#include "header.h"

int height = 33, width = 115, length = 10,p =0, score=0, bestscore, run =0;
float speed = 15;
bool apple_= true , not_pause = false;
char direction = 'r'; 
vector<vector<int>> coo = {{10,10}};
vector<int> apple_xy ={-1,-1};



int main()
{
    do
    {
        system("clear");
        cout << "\n\n\n\t\t\t1.Play Game\n" 
        << "\n\n\n\t\t\t2.Check High score\n"
        << "\n\n\n\t\t\t3.Exit\n";
        switch (getch())
        {
            case '1':
                system("clear");
                game(coo, width,height,score,direction,apple_xy,apple_,run,bestscore,length,not_pause,speed);
                break;
            case '2':
                system("clear");
                file(bestscore, score);
                cout << "\n\n\n\t\t\tHigh Score:\t" << bestscore;
                getch();
                break;
            case '3':
                exit(0);
                break;
            default:
                system("clear");
                cout << "Inalid Input\n";
                getch();
                break;
        }
        system("clear");
    }while (true);
     
}








