#include "header.h"

int main(void)
{
    thread th1(input);
    srand(time(NULL));
    poll();
    do
    {
        print();
        move();  
    } 
    while (run);
    return 0;
    
}