#include <iostream>
using namespace std;

int main() {

	// variables
	int userInput = 0;
	int smallestMultiple;

	// while loop that repeats until user enters a positive number
	while (userInput <= 0) {

		// user prompt
		cout << "Please enter an integer greater than 0: ";
		cin >> userInput;
	}

	// math to determine smallest multiple
	smallestMultiple = ((userInput / 4) + 1) * 4;

	// output
	cout << "The smallest multiple of 4 greater than " << userInput << " Is "
		<< smallestMultiple;
	
	return 0;
}
