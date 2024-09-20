#include "PIN.H"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	// random seed generatro
	srand(time(0));

	// making random 4 digit pin
	int randomPin = rand() % 9000 + 1000;
	string randomPinString = to_string(randomPin);

	// creating pin object with random pin
	Pin correctPin;
	correctPin.SetPin(randomPinString);

	string userInput;
	Pin userPin;
	bool correct = false;

	cout << randomPin << endl;

	while (!correct) {
		cout << "Enter a 4 digit pin: ";
		cin >> userInput;

		userPin.SetPin(userInput);

		if (userPin == correctPin) { 
			correct = true;
			correctPin.SetView(true);
			cout << "Correct! The Pin is: " << correctPin << endl;
		}
		else {
			cout << "Incorrect Pin. Try again." << endl;
		}
	}
	
	return 0;

}
