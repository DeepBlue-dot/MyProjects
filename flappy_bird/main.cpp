#include "header.h"

void game()
{
    print();
    while (run)
    {
        move();
        print();        
    }
    
}

int main(void)
{
    thread th1(input);
    srand(time(NULL));
    system("clear");   
    file(bestscore, score);
    poll();
    do
    {
        game();
    } while (true);

    return 0;
}