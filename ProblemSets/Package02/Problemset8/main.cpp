#include "Vector.h"

#include <iostream>
using namespace std;

int main() {
	
	// initiallizing vector to hold 30 int elements
	Vector<int> vec(30);

	// assigning first 30 numbers to be multiples of 4
	for (int i = 1; i <= 30; i++) {
		vec[i] = (i + 1) * 4; 
	}

	// displaying contents
	cout << "The elements in the array are: " << vec.ToString();

	// resizing the array to hold only 15 elements
	vec.ReSize(15);

	// Displaying elements after resize
	cout << "The new array holds these elements: " >> vec.ToString();

}