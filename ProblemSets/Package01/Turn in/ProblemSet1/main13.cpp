#include <iostream>
using namespace std;

int main() {

	// variables
	double sideA;
	double sideB;
	double sideC;

	// user prompt and input
	cout << "Please enter the length of one side: ";
	cin >> sideA;
	cout << "Please enter the length of the other side: ";
	cin >> sideB;

	// math
	sideC = sideA * sideA + sideB * sideB;

	// output
	cout << "The length of the hypotenuse is: " << sideC;

	return 0;
}
