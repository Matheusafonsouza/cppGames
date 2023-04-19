#include <iostream>
#include <string>
#include <map>

using namespace std;

const string SECRET_WORD = "APPLE";
map<char, bool> alreadyChoiced;

bool checkLetterExists(char playerChar) {
    for(char letter : SECRET_WORD) {
        if (playerChar == letter) {
            return true;
        }
    }
    return false;
}

int main () {
    cout << "***********************" << endl;
    cout << "* Welcome to the game *" << endl;
    cout << "***********************" << endl;

    cout << "The secred word is " << SECRET_WORD << endl;

    char playerLetter;
    int attempts = 0;
    double points = 1000.0; 
    while(true) {
        for(char letter : SECRET_WORD) {
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
