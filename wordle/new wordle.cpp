#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_WRONG = 6; // maximum number of incorrect guesses allowed

vector<string> words; // collection of secret words

void initializeWords() {
    words.push_back("hello");
    words.push_back("world");
    words.push_back("computer");
    words.push_back("programming");
    words.push_back("algorithm");
}

string getRandomWord() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void displayWord(string word) {
    cout << "The secret word is " << word.length() << " letters long." << endl;
}

char getGuess() {
    char guess;
    cout << "Enter your guess: ";
    cin >> guess;
    guess = tolower(guess); // convert to lowercase
    return guess;
}

void updateDisplay(string secretWord, string displayWord, char guess) {
    for (int i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == guess) {
            displayWord[i] = guess;
        }
    }
    cout << "Current word: " << displayWord << endl;
}

int getIncorrectGuesses(string secretWord, string displayWord) {
    int incorrectGuesses = 0;
    for (int i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] != displayWord[i]) {
            ++incorrectGuesses;
        }
    }
    return incorrectGuesses;
}

bool isGameOver(int incorrectGuesses) {
    return incorrectGuesses >= MAX_WRONG;
}

bool isWordGuessed(string secretWord, string displayWord) {
    return secretWord == displayWord;
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice == 'y';
}

int main() {
    initializeWords();
    
    do {
        string secretWord = getRandomWord();
        string displayWord(secretWord.length(), '-');
        int incorrectGuesses = 0;
        
        displayWord(secretWord);
        
        while (!isGameOver(incorrectGuesses) && !isWordGuessed(secretWord, displayWord)) {
            char guess = getGuess();
            
            if (secretWord.find(guess) != string::npos) {
                updateDisplay(secretWord, displayWord, guess);
            } else {
                ++incorrectGuesses;
                cout << "Sorry, '" << guess << "' is not in the word. You have " << MAX_WRONG - incorrectGuesses << " guesses left." << endl;
            }
        }
        
        if (isWordGuessed(secretWord, displayWord)) {
            cout << "Congratulations! You guessed the word." << endl;
        } else {
            cout << "Sorry, you ran out of guesses. The word was '" << secretWord << "'." << endl;
        }
    } while (playAgain());
    
    return 0;
}