#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <windows.h> 
#include <cstdlib>
#include <conio.h>

using namespace std;

int hieght = 35, width = 100, length = 10,p =0, speed = 1, score=0, bestscore;
bool apple_= true , not_pause = false;
int run = 0;
char direction = 'r';

vector<vector<int>> coo = {{10,10}};
vector<int> apple_xy ={-1,-1};

void snake(int l);
void game_over();
void check();
void input();
void move();
void apple();
void print();
void file();



int main()
{
    thread th1(input);
    snake(length);
    srand(time(NULL));
    file();
    do
    {
        if (run == 0)
        {
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
            cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
            cout << "\n\t\tGAME OVER!!\n";
            run = 2;
        }

    }while (true);
     
}

void print()
{
    cout << "Score: \t"<<score << "\tHigh Score: \t"<< bestscore <<endl;
    for(int h = 0; h < hieght; h++)
        {
            for (int w = 0; w < width;)
            {           
                if(h == 0)
                {
                    cout << "_";
                    w++;
                }
                else if (h == hieght-1)
                {
                    if(w==0)
                    {
                        cout << "|";
                        w++;
                    }
                    else if( w==width-1)
                    {   
                        cout << "|";
                        w++;
                    }
                    else
                    {
                        cout << "_";
                        w++;
                    }
                }
                else if(w == 0)
                {
                    cout << "|";
                    w++;
                }
                else if (w == width-1)
                {
                    cout << "|";
                    w++;
                }
                else
                {
                    bool print = false;
                    
                    for (vector x : coo)
                    {
                        if(w == x[0] && h == x[1])
                        {
                            cout << "x";
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
                            cout <<"*";
                            w++;                        
                    }
                
                    else if (print)
                        {
                            cout << " ";
                            w++;
                        }
                }
            }
            cout << "\n";
        }
    sleep(speed);
    system("cls");

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

void input()
{
    do {
         switch (getch())
            {
                case 'w':
                    if(direction != 'd' && direction != 'u' && not_pause)
                    {
                        direction = 'u';
                    }
                    break;
                case 's':
                    if(direction != 'd' && direction != 'u' && not_pause)
                    {
                        direction = 'd';
                    }
                    break;
                case 'a':
                    if(direction != 'l' && direction != 'r' && not_pause)
                    {
                        direction = 'l';
                    }
                    break;
                case 'd':
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
                        system("cls");
                        score = 0;
                    }
                    break;
                case 'q':
                    system("cls");
                    exit(0);
                    break;
                default:
                    break;
            }
	} while(true);
	 
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

void game_over()
{
    file();
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

void snake(int l)
{
    for(int i = 0; i < (l-1); i++)
    {
        coo.push_back({coo[coo.size()-1][0]+1,coo[coo.size()-1][1]});
    }
}


void file()
{
    ifstream fin ("best_score.txt");
    if(fin.is_open())
    {
        fin >> bestscore;
    }
    else
    {
        ofstream fout ("best_score.txt");
        fout << 0;
        bestscore = 0;
    }
    ofstream fout ("best_score.txt");
    if (score > bestscore)
    {
        fout << score;
        bestscore = score;
    }
    else
    {
        fout << bestscore;
    }

}