#include <iostream>
#include <cmath>
using namespace std;

// function prototype
bool IsPrime(int);

int main() {

	// variable
	int userInt;

	// user prompt
	cout << "Please enter an integer: ";
	cin >> userInt;

	// if loop determines true = prime != not prime
	if (IsPrime(userInt)) {
		cout << "Your integer is prime!";
	} else {
		cout << "Your integer is not prime!";

	}

}

// function definition
bool IsPrime(int userInt) {

	// 1 and 0 are already prime
	if (userInt <= 1) {
		return false;
	}

	// for loop checks if user number divided by loop number = 0
	for (int i = 2; i <= sqrt(userInt); i++) {
		if (userInt % i == 0) {
			return false;
		}
	}
	return true;
}