#include "header.h"

const int width = 101;
const int height = 33;
int score = 0;
int bestscore = 0;
double gravity = 0;
float speed =3;
int space_index;
size_t i = 0, j=0;

bool start = true;
bool run = false;

vector <int> bird = {10,10};
vector <string> border = {"<", "-"};
vector<vector<int>> wall={{width,height/2}};

int last;

