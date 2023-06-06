#include "header.h"

void input()
{
    do {
         switch (getch())
            {
                case 65:
                    break;
                case 66:
                    break;
                case 68:
                    break;
                case 67:
                    break;
                case 32:
                    if(bird[1] > 3)
                        gravity = -0.7;
                    break;
                case 'q':
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
