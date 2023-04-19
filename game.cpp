#include <iostream>

using namespace std;

int main () {
    cout << "***********************" << endl;
    cout << "* Welcome to the game *" << endl;
    cout << "***********************" << endl;

    cout << "Choose the difficulty" << endl;
    cout << "Easy (E), Normal (N), Hard (H)" << endl;

    char difficulty;
    cin >> difficulty;

    int playerAttemptsLimit;

    if (difficulty == 'E') {
        playerAttemptsLimit = 15;
    } else if (difficulty == 'M') {
        playerAttemptsLimit = 10;
        
    } else if (difficulty == 'H') {
        playerAttemptsLimit = 5;
    }

    const int SECRET_NUMBER = 32;
    cout << "The secret number is " << SECRET_NUMBER << endl;

    int number, attempts = 0;
    double points = 1000.0; 
    while(attempts < playerAttemptsLimit) {
        attempts++;
        cout << "What is your number?" << endl;
        cin >> number;
        cout << "Your number is " << number << endl;

        if (number == SECRET_NUMBER) {
            cout << "Congratulations! Your number is correct :)" << endl;
            break;
        } else if (number > SECRET_NUMBER) {
            cout << "Wrong choice! Your number is bigger than the secret number." << endl;
        } else if (number < SECRET_NUMBER) {
            cout << "Wrong choice! Your number is smaller than the secret number." << endl;
        }

        double lossPoints = abs(number - SECRET_NUMBER) / 2.0;
        points = points - lossPoints;
    }

    if (attempts < playerAttemptsLimit) {
        cout << "You answered the correct number in " << attempts << " attempts!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your pontuation was " << points << endl;
    } else {
        cout << "You losed :( try again!" << endl;
    }
}
