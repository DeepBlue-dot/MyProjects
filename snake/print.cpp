#include "header.h"

<<<<<<< HEAD
void print(vector<vector<int>> &coor, int &score, int &bestscore, int &hieght, int &width, float &speed, vector<int> &apple_xy)
{
    char display[hieght][width+1] = {' '};
=======
void print(vector<vector<int>> &coor, int &score, int &bestscore, int &hieght, int &width, int &speed, vector<int> &apple_xy)
{
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
    cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
    for(int h = 0; h < hieght; h++)
        {
            for (int w = 0; w < width;)
            {           
                if(h == 0)
                {
<<<<<<< HEAD
                    //putc('_', stdout);
                    display[h][w] = '_';
=======
                    printf("_");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                    w++;
                }
                else if (h == hieght-1)
                {
                    if(w==0)
                    {
<<<<<<< HEAD
                        //putc('|', stdout);
                        display[h][w] = '|';
=======
                        printf("|");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                        w++;
                    }
                    else if( w==width-1)
                    {   
<<<<<<< HEAD
                        //putc('|', stdout);
                        display[h][w] = '|';
=======
                        printf("|");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                        w++;
                    }
                    else
                    {
<<<<<<< HEAD
                        //putc('_', stdout);
                        display[h][w] = '_';
=======
                        printf("_");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                        w++;
                    }
                }
                else if(w == 0)
                {
<<<<<<< HEAD
                    //putc('|', stdout);
                    display[h][w] = '|';
=======
                    printf("|");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                    w++;
                }
                else if (w == width-1)
                {
<<<<<<< HEAD
                    //putc('|', stdout);
                    display[h][w] = '|';
=======
                    printf("|");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                    w++;
                }
                else
                {
                    bool print = false;
                    
                    for (vector x : coor)
                    {
                        if(w == x[0] && h == x[1])
                        {
<<<<<<< HEAD
                            //putc('x', stdout);
                            display[h][w] = 'x';
=======
                            printf("x");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
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
<<<<<<< HEAD
                            //putc('*', stdout);
                            display[h][w] = '*';
=======
                            printf("*");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                            w++;                        
                    }
                
                    else if (print)
                        {
<<<<<<< HEAD
                            //putc(' ', stdout);
                            display[h][w] = ' ';
=======
                            printf(" ");
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
                            w++;
                        }
                }
            }
<<<<<<< HEAD
            //putc('\n', stdout);
            display[h][width] = '\n';
        }
    fwrite( display, sizeof(display), 1, stderr);
    this_thread::sleep_for(chrono::microseconds((int)speed*1000));
=======
            printf("\n");
        }
    this_thread::sleep_for(chrono::microseconds(speed*1000));
>>>>>>> 35f04c7a8416da1efec83d934c0200fefd5abfc1
    system("clear");

}