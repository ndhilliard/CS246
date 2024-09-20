#include <iostream>
using namespace std;

// function prototype
void SumOfNumbers(double, double);

int main() {

	// function call
	SumOfNumbers(userInput1, userInput2);

	return 0;
}

// function definitions
/* function prompts user to enter 2 numbers.
*  function squares both numbers and adds them together.
*  finally it'll display the output
 */
void SumOfNumbers(double x, double y) {

	// creating variables
	double x, y;
	double squareX = x * x;
	double squareY = y * y;

	// user prompt and assignting variables
	cout << "Please enter a number: ";
	cin >> x;
	cout << "Please enter another number: ";
	cin >> y;

	cout << "The sum of your numbers squared is: " << squareX + squareY;
}