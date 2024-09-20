#include <iostream>
using namespace std;

// function prototype
void StringSwap();

int main() {

	StringSwap(userString1, userString2);

}

// fucntion definitions

void StringSwap() {

	// variables
	string userString1, userString2;
	string holder = string1;
	string1 = string2;
	string2 = holder;

	// prompt
	cout << "Please enter a string: ";
	cin >> userString1;
	cout << "Please enter another string: ";
	cin >> userString2;
	cout << "Your strings were: " << userString1 << ", and "
		<< userString2 << endl;

	cout << "Your strings have been swapped! They are now... " << endl;
	cout << userString1 << " and " << userString2;
}
