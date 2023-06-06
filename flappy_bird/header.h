#ifndef flappy
#define flappy

#include <iostream>
#include <vector>
#include <termios.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <array>


using namespace std;

extern const int width;
extern const int height;
extern float speed;
extern size_t i,j;

extern int score;
extern int bestscore;
extern double gravity;
extern int space_index;
extern int last;

extern bool start;
extern bool run;

extern vector <int> bird;
extern vector <string> border;
extern vector<vector<int>> wall;

void print();
int getch(void);
void input();
void move();
void poll();
char find_char (int& w,  int& h);
bool Find(int& w,  int& h);

#endif