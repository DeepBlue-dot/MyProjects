#include "header.h"

void input(char &direction, bool &not_pause, int &score, int &run, float &speed)
{
    do {
         switch (getch())
            {
                case 65:
                    if(direction != 'd' && direction != 'u' && not_pause)
                    {
                        direction = 'u';
                    }
                    break;
                case 66:
                    if(direction != 'd' && direction != 'u' && not_pause)
                    {
                        direction = 'd';
                    }
                    break;
                case 68:
                    if(direction != 'l' && direction != 'r' && not_pause)
                    {
                        direction = 'l';
                    }
                    break;
                case 67:
                    if(direction != 'l' && direction != 'r' && not_pause)
                    {
                        direction = 'r';
                    }
                    break;
                case 32:
                    if(run == 0)
                    {
                        if(not_pause)
                        {
                            not_pause = false;
                        }
                        else
                        {
                            not_pause = true;
                        }
                    }
                    else if(run == 2)
                    {
                        run = 0;
                        system("clear");
                        score = 0;
                    }
                    break;
                case 'q':
                    system("clear");
                    run = 3;
                    break;
                case 'i':
                    speed ++;
                    break;
                case 'o':
                    speed --;
                    break;
                
                default:
                    break;
            }
	} while(true);
	 
}
