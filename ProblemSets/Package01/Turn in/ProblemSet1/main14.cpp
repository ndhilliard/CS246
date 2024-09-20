#include <iostream>
using namespace std;

int main() {

	// variables
	int userInt;
	bool even;

	//user prompt
	cout << "Please enter an integer: ";
	cin >> userInt;

	// if statement that determines whether odd and if not its even!
	if (userInt % 2 != 0) {
		cout << userInt << " is odd!";
	} else {
		cout << userInt << " is Even!";
	}

	return 0;
}