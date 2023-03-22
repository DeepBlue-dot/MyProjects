#include "header.h"

void print(vector<vector<int>> &coor, int &score, int &bestscore, int &hieght, int &width, int &speed, vector<int> &apple_xy)
{
    cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
    for(int h = 0; h < hieght; h++)
        {
            for (int w = 0; w < width;)
            {           
                if(h == 0)
                {
                    printf("_");
                    w++;
                }
                else if (h == hieght-1)
                {
                    if(w==0)
                    {
                        printf("|");
                        w++;
                    }
                    else if( w==width-1)
                    {   
                        printf("|");
                        w++;
                    }
                    else
                    {
                        printf("_");
                        w++;
                    }
                }
                else if(w == 0)
                {
                    printf("|");
                    w++;
                }
                else if (w == width-1)
                {
                    printf("|");
                    w++;
                }
                else
                {
                    bool print = false;
                    
                    for (vector x : coor)
                    {
                        if(w == x[0] && h == x[1])
                        {
                            printf("x");
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
                            printf("*");
                            w++;                        
                    }
                
                    else if (print)
                        {
                            printf(" ");
                            w++;
                        }
                }
            }
            printf("\n");
        }
    this_thread::sleep_for(chrono::microseconds(speed*1000));
    system("clear");

}