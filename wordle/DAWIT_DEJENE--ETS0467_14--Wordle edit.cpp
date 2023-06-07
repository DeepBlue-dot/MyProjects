#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
//just when it starts running laklgn tnx ... i will try it here as well
using namespace std;

const int word_length = 5;
const int number_of_guess = 6;
const int partly_matched = 1;
const int matched = 2;
const int unmatched = 0;
 //this part u can ignore because i couldnt fix it
//void touppercase(string &input)
//{
//	transform(input.begin(), input.end(), input.begin(),[](unsigned char c) 
//	{ return touppercase(c); });
//}

string fetchrandomword()
{
	// todo fetch random wor from api (e.g. wordsapi)
	return "ready";
}

bool isvalidword(string word)
{
	//todo check word correctness from api
	return word.length() == word_length && word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == string :: npos;
}//30


void markmatches (vector < vector<int>> &matches, int currentguessindex, string targetword, string guessword) 
{

	for(int i = 0; i < guessword.length(); i++) 
	{
		matches[currentguessindex][i] = not_matched;
	}
	
	for (int i = 0; i< guessword.length(); i++) 
	 { 

	  for (int j = 0; j < targetword.length(); j++) 
	  {
	  	if (guessword[i] == targetword[j]) 
		  {
		  	if (i == j) 
			  {
			  	matches[currentguessindex][i] = matched; // 41
				  break; 
			  }
			  else 
			  {
			  	matches[currentguessindex][i] = partly_matched //44
			  }
		  }
	  }
	 }
}

bool isallmatched(string targetword, string guessword)
{
	for (int i = 0; i < targetword.lenth(); i++) 
	{
		if (targetword[i] != guessword[i]) return false;
	}
	
	return true;
}

void printwordle(vector<vector<int>> matches, vector <string> guesses, int currentguessindex)
{
	//clear console 
	system("cls");
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "                                         __  __     "<<endl;       
    cout << "                                        |  \\|  \ "<<endl;          
    cout << "  __   __   __   ______    ______    ____| ##| ##  ______  "<<endl;
    cout << " |  \\ |  \\ |  \\ /      \\  /      \\  /      ##| ## /      \\ "<<endl;
    cout << " | ## | ## | ##|  ######\|  ######\\|  #######| ##|  ######\\"<<endl;
    cout << " | ## | ## | ##| ##  | ##| ##   \\##| ##  | ##| ##| ##    ## "<<endl;
    cout << " | ##_/ ##_/ ##| ##__/ ##| ##      | ##__| ##| ##| ########"<<endl;
    cout << "  \\##   ##   ## \\##    ##| ##       \\##    ##| ## \\##     \\" <<endl;  
    cout << "   \\#####\\####   \\######  \\##        \\####### \\##  \\####### "<<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    
    for (int i = 0; i <= currentguessindex && i < guesses.size();i++) 
	{
		string separator = "-";
		string padding ="|";
		string text ="|";
		
		for (int j = 0; j < guesses[i].length(); j++) 
		{
			separator += "------";
			padding += "     |";
			char value = toupper(guesses[i][j]);
			text += "  ";

			if(matches[i][j] == partly_matched) 
			{
				// print text with color
				text += "\033[33m";
			}
			else if (matches[i][j] == matched) 
			{
				text += "\033[32m";
			}
			
			text += value;
			
			if (matches[i][j] == partly_matched || matches[i][j] == matched) 
			{
				//close color
				text += "\033]0m";
			}
			
			text += "  |";
 		}
 		
 		if (i == 0) 
		 {
		 	cout << separator << endl;
		 }
		 
		 cout << padding << endl;
		 cout << text << endl;
		 cout << padding << endl;
		 cout << separator << endl;
	} 
}

int main ()
{
	vector <string> guesses(number_of_guesses);
	vector <vector<int>> matches(number_of_guesses, vector<int>(word_length));
	string targetword = fetchrandomword();
	touppercase(targetword);
	
	 string input;
	 int currentguesscount = 0;
	 
	 //just print the tite
	 printwordle(matches, guesses, -1);
	 
	 while (currentguesscount < number_of_guesses)
	  {
	  	do
	  	  {
	  	  	cout << "please enter your guess(word length must be " + to_string(word_length) + ") or type q/Q to quit the game";
	  	  	getline(cin,  input);
	  	  	touppercase(input);
		  }
		  while (input != "Q" && !isvalidword(input));
		  
		  if (input == "Q")
		   {
		   	cout << "Quit Game?" <<endl;
		   	break;
		   }
		   
		   guesses [currentguesscount] = input;
		   markmatches(matches, currentguesscount , targetword, input);
		   printwordle(matches, guesses, currentguesscount);
		   
		   if (isallmatched(targetword,input)) 
		   {
		   	cout << " you Win !!!" << endl;
		   	break;
		   }
	  	currentguesscount++ ;
	  }
	
	
}
