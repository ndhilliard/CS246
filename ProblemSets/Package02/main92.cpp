#include "Vector.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RemoveDuplicates(Vector<T>& vec) {
	for (long i = 0; i < vec.Size(); i++) {
		for (long j = i +1; j < vec.Size(); j++)
			if (vec[i] == vec[j]) {
				vec.Remove(j);
				j--; 
			}
	}
}

int main() {
	srand(time(0));
	Vector<int> intVector;

	for (int i = 0; i < 20; i++) {
		intVector.Append((rand() % 15) + 1);
	}

	cout << "Original vector: " << intVector.ToString() << endl;

	RemoveDuplicates(intVector);

	cout << "Vector after duplicates removed: " << intVector.ToString(); << endl;

	return 0;
}