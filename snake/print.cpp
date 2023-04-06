#include "header.h"

void print(vector<vector<int>> &coor, int &score, int &bestscore, int &hieght, int &width, float &speed, vector<int> &apple_xy)
{
    char display[hieght][width+1] = {' '};
    cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
    for(int h = 0; h < hieght; h++)
        {
            for (int w = 0; w < width;)
            {           
                if(h == 0)
                {
                    //putc('_', stdout);
                    display[h][w] = '_';
                    w++;
                }
                else if (h == hieght-1)
                {
                    if(w==0)
                    {
                        //putc('|', stdout);
                        display[h][w] = '|';
                        w++;
                    }
                    else if( w==width-1)
                    {   
                        //putc('|', stdout);
                        display[h][w] = '|';
                        w++;
                    }
                    else
                    {
                        //putc('_', stdout);
                        display[h][w] = '_';
                        w++;
                    }
                }
                else if(w == 0)
                {
                    //putc('|', stdout);
                    display[h][w] = '|';
                    w++;
                }
                else if (w == width-1)
                {
                    //putc('|', stdout);
                    display[h][w] = '|';
                    w++;
                }
                else
                {
                    bool print = false;
                    
                    for (vector x : coor)
                    {
                        if(w == x[0] && h == x[1])
                        {
                            //putc('x', stdout);
                            display[h][w] = 'x';
                            w++; 
                            print = false;
                            break;                       
                        }             
                        else
                        {
                            print = true;
                        }
                            
                    }
                    if (w == apple_xy[0] && h == apple_xy[1])
                    {
                            //putc('*', stdout);
                            display[h][w] = '*';
                            w++;                        
                    }
                
                    else if (print)
                        {
                            //putc(' ', stdout);
                            display[h][w] = ' ';
                            w++;
                        }
                }
            }
            //putc('\n', stdout);
            display[h][width] = '\n';
        }
    fwrite( display, sizeof(display), 1, stderr);
    this_thread::sleep_for(chrono::microseconds((int)speed*1000));
    system("clear");

}