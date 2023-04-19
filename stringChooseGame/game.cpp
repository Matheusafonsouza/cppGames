#include <iostream>
#include <string>

using namespace std;

int main () {
    cout << "***********************" << endl;
    cout << "* Welcome to the game *" << endl;
    cout << "***********************" << endl;

    const string SECRET_WORD = "APPLE";
    cout << "The secred word is " << SECRET_WORD << endl;

    string word;
    int attempts = 0, playerAttemptsLimit = 10;
    double points = 1000.0; 
    while(attempts < playerAttemptsLimit) {
        attempts++;
        cout << "What is your word?" << endl;
        cin >> word;
        cout << "Your word is " << word << endl;

        if (word == SECRET_WORD) {
            cout << "Congratulations! Your word is correct :)" << endl;
            break;
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
