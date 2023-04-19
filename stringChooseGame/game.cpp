#include <iostream>
#include <string>

using namespace std;

const string SECRET_WORD = "APPLE";

bool checkLetterExists(char playerChar) {
    for(int i = 0; i < SECRET_WORD.size(); i++) {
        if (playerChar == SECRET_WORD[i]) {
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

    char playerChar;
    int attempts = 0, playerAttemptsLimit = 10;
    double points = 1000.0; 
    while(attempts < playerAttemptsLimit) {
        attempts++;
        cout << "What is your char?" << endl;
        cin >> playerChar;
        cout << "Your char is " << playerChar << endl;

        if (checkLetterExists(playerChar)) {
            cout << "Congratulations! Your char is correct :)" << endl;
            break;
        } else {
            "Wrong choice! Try again.";
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
