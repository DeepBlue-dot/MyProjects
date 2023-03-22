#ifndef SNAKE
#define  SNAKE

#include <iostream>
#include <unistd.h>
#include <vector>
#include <termios.h>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std;

int getch(void);
void snake(int &l, vector<vector<int>> &coo);
void game_over(vector<int> &apple_xy, int &run, vector<vector<int>> &coo, char &direction, bool &not_pause, bool &apple_, int &bestscore, int &score, int &length);
void check(vector<vector<int>> &coo, int &width, int &hieght, int &score, char &direction, vector<int> &apple_xy, bool &apple_, int &run, int &bestscore,int &length, bool &not_pause);
void input(char &direction, bool &not_pause, int &score, int &run);
void move (char &direction, vector<vector<int>> &coo);
void apple(bool &apple_, vector<int> &apple_xy, int &width, int &hieght, vector<vector<int>> &coo);
void print(vector<vector<int>> &coor, int &score, int &bestscore, int &hieght, int &width, int &speed, vector<int> &apple_xy);
void file(int &bs, int &s);


#endif