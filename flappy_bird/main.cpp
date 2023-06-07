#include "header.h"


void game()
{
    poll();
    do
    {
        print();
        move();  
    } 
    while (run);   

}


int main(void)
{
    thread th1(input);
    srand(time(NULL));
    do
    {
        game();
        game_over();
    }while(true);

    return 0;
    
}