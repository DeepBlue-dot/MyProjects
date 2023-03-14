#include <iostream>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include <thread>
#include <chrono>




using namespace std;

int hieght = 35, width = 100, length = 50,p =0, speed = 10, score=0;
bool apple_= true , not_pause = false;
int run = 0;
char direction = 'r',c;

vector<vector<int>> coo = {{10,10}};
vector<int> apple_xy ={-1,-1};


int getch(void) 
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void snake(int l)
{
    for(int i = 0; i < (l-1); i++)
    {
        coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
    }
}

void game_over()
{
    run = 1;
    coo.clear();
    coo.push_back({10,10});
    snake(length); 
    direction = 'r';
    apple_=true;
    apple_xy.clear();
    apple_xy[0] = -1;
    apple_xy[1] = -1;
    not_pause = false;

}

void check()
{
    for (int i=0; i < coo.size(); i++)
    {
        if(coo[i][0] < 1 || coo[i][0] >= width-1 || coo[i][1] < 1 || coo[i][1] >= hieght-1)
        {
            game_over();
        }
    
        if (coo[i][0] == apple_xy[0] && coo[i][1] == apple_xy[1])
        {
            apple_ = true;
                switch (direction)
                {
                    case 'u':
                        coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]-1});
                        break;
                    case 'd':
                        coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]+1});
                        break;
                    case 'r':
                        coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
                        
                        break;
                    case 'l':
                        coo.push_back({coo[coo.size()-1][0]-1,coo[coo.size()-1][1]});
                        break;
                    default:
                        break;
                }
            score+=1;
        }
        
    }
    for(int p =0; p < coo.size(); p++)
    {
        for(int q =0; q < coo.size(); q++)
        {
            if(p != q && coo[p][0] == coo[q][0] && coo[p][1] == coo[q][1])
            {
                game_over();
            }
        }

    }
    
}



void input()
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
                case 'v':
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
                default:
                    break;
            }
	} while(true);
	 
}

void move()
{
    switch (direction)
    {
        case 'u':
            coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]-1});
            coo.erase(coo.begin());
            break;
        case 'd':
            coo.push_back({coo[coo.size()-1][0],coo[coo.size()-1][1]+1});
            coo.erase(coo.begin());
            break;
        case 'r':
            coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
            coo.erase(coo.begin());
            break;
        case 'l':
            coo.push_back({coo[coo.size()-1][0]-1,coo[coo.size()-1][1]});
            coo.erase(coo.begin());
            break;
        default:
            break;
    }
    
}

void apple()
{
    if(apple_)
    {
        bool loop = true;
        while (loop)
        {
            apple_xy[0] = rand() % (width);
            apple_xy[1] = rand() % (hieght);
            for (vector e : coo)
            {
                if(e[0] == apple_xy[0] && e[1] == apple_xy[1])
                {
                    loop = true;
                    break;
                }
                else
                {
                    if(0 < apple_xy[0]  && apple_xy[0]  < width-1 && 0 < apple_xy[1]  && apple_xy[1] < hieght-1)
                    {
                        loop = false;
                    }
                }
            }
        }
        apple_ = false;
    }
        
}

void print()
{
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
                    
                    for (vector x : coo)
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

int main()
{
    thread th1(input);
    snake(length);
    srand(time(NULL));
    do
    {

        if (run == 0)
        {
            cout << "Score: \t"<<score <<endl;
            if(not_pause)
            {
                print();
                move();
                check();
                apple();
                
            }
            else
            {
                print();
                
            }
        }
        else if(run == 1)
        {
            cout << "Score: \t"<< score << endl;
            cout << "\n\t\tGAME OVER!!\n";
            run = 2;
        }

    }while (true);
     

}