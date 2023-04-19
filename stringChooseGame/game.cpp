#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string secret_word = "APPLE";
map<char, bool> alreadyChoiced;
vector<char> wrongLetters;

bool checkLetterExists(char playerChar) {
    for(char letter : secret_word) {
        if (playerChar == letter) {
            return true;
        }
    }
    return false;
}

bool checkWrongWord() {
    for(char letter : secret_word) {
        if(!alreadyChoiced[letter]) {
            return true;
        }
    }
    return false;
}

bool notHanged() {
    return wrongLetters.size() < secret_word.length();
}

vector<string> readFile() {
    ifstream file;
    file.open("words.txt");

    int wordsLength;
    file >> wordsLength;

    cout << "The file have " << wordsLength << " words." << endl;

    vector<string> words;

    for(int i = 0; i < wordsLength; i++) {
        string word;
        file >> word;
        cout << "On line " << i << " : " << word << endl;
        words.push_back(word);
    }
    
    return words;
}

string chooseWord() {
    vector<string> words = readFile();

    srand(time(NULL));
    int index = rand() % word.size();

    secret_word = words[index];
}

int main () {
    cout << "***********************" << endl;
    cout << "* Welcome to the game *" << endl;
    cout << "***********************" << endl;

    chooseWord();

    char playerLetter;
    int attempts = 0;
    double points = 1000.0; 
    while(checkWrongWord() && notHanged()) {
        cout << "Wrong letters: ";
        for(char letter : wrongLetters) {
            cout << letter << " ";
        }
        cout << endl;

        for(char letter : secret_word) {
            if (alreadyChoiced[letter]) {
                cout << letter << " ";
            } else {
                cout << "_" << " ";
            }
        }
        cout << endl;

        attempts++;
        cout << "What is your letter?" << endl;
        cin >> playerLetter;
        cout << "Your letter is " << playerLetter << endl;

        if (checkLetterExists(playerLetter)) {
            cout << "Congratulations! Your letter is correct :)" << endl;
            alreadyChoiced[playerLetter] = true;
        } else {
            cout << "Wrong choice! Your letter isnt on the secret word." << endl;
            alreadyChoiced[playerLetter] = false;
            wrongLetters.push_back(playerLetter);
        }
    }

    // if (attempts < playerAttemptsLimit) {
    //     cout << "You answered the correct word in " << attempts << " attempts!" << endl;
    //     cout.precision(2);
    //     cout << fixed;
    //     cout << "Your pontuation was " << points << endl;
    // } else {
    //     cout << "You losed :( try again!" << endl;
    // }
}
