#include <iostream>
using namespace std;

int main() {

	// variables
	int userInput = 0;

	// while loop that stops when a positive number is entered
	while (userInput <= 0) {

		//user prompt
		cout << "Please enter an integer greater than 0: ";
		cin >> userInput;
	}

		
	cout << "The first " << userInput << " perfect squares are: " << endl;

	// loops output the # of times = to user input
	for (int i = 1; i <= userInput; i++) {
		cout << i * i << endl;
	}
	
	return 0;
}