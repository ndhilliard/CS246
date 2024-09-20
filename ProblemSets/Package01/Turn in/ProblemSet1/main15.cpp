#include <iostream>
using namespace std;

int main() { 
	
	// variable
	int userInt;

	// user prompt
	cout << "Please enter and integer: ";
	cin >> userInt;

	// if statement determins is userinput is negative, 0, or positive
	if (userInt < 0) {
		cout << userInt << " is negative!";
	} else if (userInt == 0) {
		cout << userInt << " is zero!";
	} else {
		cout << userInt << " is positive!";
	}

	return 0;
}
