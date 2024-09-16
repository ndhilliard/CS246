#include <iostream>
#include <ctime>
#include "Mask.h"
#include "DekaTuple.h"
#include "Util.h"
using namespace std;

// function prototype
void RemoveDuplicates(DekaTuple<Mask>& Thing);

int main() {
	srand(time(nullptr));

	// Filling mask object with random values
	// between 1 and 10
	DekaTuple<Mask> thing;

	// displaying original mask
	cout << "Original array: " << thing.ToString() << endl;

	// function call to remove duplicates if any
	RemoveDuplicates(thing);

	// displaying mask after function call has removed duplicates
	cout << "After removing duplicates: " << thing.ToString() << endl;

	return 0;

}

// function implementation

// funciton removes any duplicated numbers 
// and replaces them with a 0
void RemoveDuplicates(DekaTuple<Mask>& thing) {
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (thing.GetValue(i) == thing.GetValue(j)) {
				thing.GetValue(j).Void();
			}
		}
	}
}
