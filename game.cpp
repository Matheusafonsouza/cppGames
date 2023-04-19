#include <iostream>

using namespace std;

int main () {
    cout << "***********************" << endl;
    cout << "* Welcome to the game *" << endl;
    cout << "***********************" << endl;

    int secretNumber = 32;
    cout << "The secret number is " << secretNumber << endl;

    int number;
    cout << "What is your number?" << endl;
    cin >> number;
    cout << "Your number is " << number << endl;

    if (number == secretNumber) {
        cout << "Congratulations! Your number is correct :)" << endl;
    } else if (number > secretNumber) {
        cout << "Wrong choice! Your number is bigger than the secret number." << endl;
    } else if (number < secretNumber) {
        cout << "Wrong choice! Your number is smaller than the secret number." << endl;
    }
}
