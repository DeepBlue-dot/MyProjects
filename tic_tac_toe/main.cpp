#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string choice = "0";
bool run = true;

int turn = 1;

string dispaly [] = {
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                        " ", "1", " ", "|", " ", "2", " ", "|", " ", "3", " ", "\n",
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                        "_", "_", "_", "|", "_", "_", "_", "|", "_", "_", "_", "\n",
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                        " ", "4", " ", "|", " ", "5", " ", "|", " ", "6", " ", "\n",
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                        "_", "_", "_", "|", "_", "_", "_", "|", "_", "_", "_", "\n",
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                        " ", "7", " ", "|", " ", "8", " ", "|", " ", "9", " ", "\n",
                        " ", " ", " ", "|", " ", " ", " ", "|", " ", " ", " ", "\n",
                                            
                    };

int length = sizeof(dispaly)/ sizeof(dispaly[0]);

string arr1[ sizeof(dispaly)/ sizeof(dispaly[0])];

        

string xo [] = {
                    " "," "," ",
                    " "," "," ",
                    " "," "," "
                };

void arr (bool revers)
{
    if(revers)
    {
        for (int i=0; i<length; i++)
        {
            dispaly[i] = arr1[i];
            if (i < 9)
            {
                xo[i] = " ";
            }
            turn = 1;
            
        }
            
    }
    else
    {
        for (int i=0; i<length; i++)
            arr1[i] = dispaly[i];
    }

}

void print(int s)
{

    for(int i = 0; i < s; i++)
        {
            if (choice == dispaly[i])
            {
                turn ++; 
                if (turn % 2 != 0)
                {
                    dispaly[i] = "O";
                    xo[stoi(choice)-1] = "O";
                }
                else
                {
                     dispaly[i] = "X";
                     xo[stoi(choice)-1] = "X";
                }
                
            }
            cout << "\t" << dispaly[i];
        }
    for (int i = 0; i < 7; i += 3)
    {
        if(xo[i] == xo[i+1] && xo[i+1] == xo[i+2])
        {
            if (xo[i] == "X")
            {
                std::system("clear");
                cout << "\t\tPlayer1 wins \n";
                cin >> choice;
                arr(true);
            }
            else if(xo[i] == "O")
             {
                std::system("clear");
                cout << "\t\tPlayer2 wins \n";
                cin >> choice;
                arr(true);
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if(xo[i] == xo[i+3] && xo[i+3] == xo[i+6])
        {
            if (xo[i] == "X")
            {
                std::system("clear");
                cout << "\t\tPlayer1 wins \n";
                cin >> choice;
                arr(true);
            }
            else if(xo[i] == "O")
             {
                std::system("clear");
                cout << "\t\tPlayer2 wins \n";
                cin >> choice;
                arr(true);
            }
        }
    }
    for (int i = 0 ; i<3; i+=2)
    {
        if(i == 0 && xo[i] == xo[i+4] && xo[i+4] == xo[i+8])
        {
            if (xo[i] == "X")
            {
                std::system("clear");
                cout << "\t\tPlayer1 wins \n";
                cin >> choice;
                arr(true);
            }
            else if(xo[i] == "O")
             {
                std::system("clear");
                cout << "\t\tPlayer2 wins \n";
                cin >> choice;
                arr(true);
            }
        }
        else if (i == 2 && xo[i] == xo[i+2] && xo[i+2] == xo[i+4])
        {
            if (xo[i] == "X")
            {
                std::system("clear");
                cout << "\t\tPlayer1 wins \n";
                cin >> choice;
                arr(true);
            }
            else if(xo[i] == "O")
             {
                std::system("clear");
                cout << "\t\tPlayer2 wins \n";
                cin >> choice;
                arr(true);
            }
        }
    }
    if(turn > 9)
        {
            system("clear");
            cout << "\t\t DRAW \n";
            cin >> choice;
            arr(true);
        }
}
    
int main ()
{
    arr(false);
    do
    {
        std::system("clear");
        cout << "\t\t\t\t\tTic Tac Toe \n \t\t\t\tPlayer1 <X> \t Player2 <O> \n";
        print(length);
        cout << "\t\t\tEnter Number to play and \"q\" to Exit. \n";
        getline(cin, choice);
        
    }
    while(choice != "q");
    return 0;
}