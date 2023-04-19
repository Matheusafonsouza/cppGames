#include <iostream>
#include <string>

using namespace std;

const string SECRET_WORD = "APPLE";

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
    int attempts = 0, playerAttemptsLimit = 10;
    double points = 1000.0; 
    while(attempts < playerAttemptsLimit) {
        attempts++;
        cout << "What is your letter?" << endl;
        cin >> playerLetter;
        cout << "Your letter is " << playerLetter << endl;

        if (checkLetterExists(playerLetter)) {
            cout << "Congratulations! Your letter is correct :)" << endl;
            break;
        } else {
            cout << "Wrong choice! Your letter isnt on the secret word." << endl;
        }
    }

    if (attempts < playerAttemptsLimit) {
        cout << "You answered the correct word in " << attempts << " attempts!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your pontuation was " << points << endl;
    } else {
        cout << "You losed :( try again!" << endl;
    }
}
