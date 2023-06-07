#include "header.h"


void print()
{
    char display[height][width+1] = {' '};
    cout << "Score: \t"<< score/29 << "\tHigh Score: \t"<< bestscore << "\tSpeed: \t" << speed <<endl;
    for(int h = 0; h < height; h++)
        {
            for (int w = 0; w < width;w++)
            {           
                if(h == 0)
                {
                    display[h][w] = border[i][0];
                    i = (i==0)?1:0;
                }
                else if (h == height-1)
                {
                    if(w==0)
                    {
                        display[h][w] = '|';
                    }
                    else if( w==width-1)
                    {   
                        display[h][w] = '|';
                    }
                    else
                    {
                        display[h][w] = border[j][0];
                        j = (j==0)?1:0;
                    }
                }
                else if(w == 0)
                {
                    display[h][w] = '|';
                }
                else if (w == width-1)
                {
                    display[h][w] = '|';
                }
                else
                {
                    display[h][w] = find_char(w,h);
                }
                
            }
            //putc('\n', stdout);
            display[h][width] = '\n';
        }
    fwrite( display, sizeof(display), 1, stderr);
    this_thread::sleep_for(chrono::microseconds((int)speed*10000));
    printf("\x1b[H\x1b[J");

}

    
