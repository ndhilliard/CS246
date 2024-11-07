#include "Vector.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> 
bool Expand(ds::Vector<T>& vec1, ds::Vector<T>& vec2) {
	bool nonAdded = true;
	for (long i = 0; i < vec1.Size(); i++) {
		if (!vec2.Contains(vec1[i])) {
			vec2.Append(vec1[i]);
			nonAdded = false;
		}
	}
	return nonAdded;
};

int main() {
	using namespace ds;
	srand(time(0));

	Vector<int> vec1;
	Vector<int> vec2;
	Vector<int> vec3;

	// assign values to vectors
	for (int i = 0; i < 10; i++) {
		vec1.Append((rand() % 10) + 1);
		vec2.Append((rand() % 10) + 1);
	}

	for (int i = 0; i < vec2.Size(); i++) {
		vec3.Append(vec2[i]);
	}

	// display vectors before expanding
	cout << "Vector 1: " << vec1.ToString() << endl;
	cout << "Vector 2: " << vec2.ToString() << endl;
	cout << "Vector 3: " << vec3.ToString() << endl;

	// expanding 1 and 2
	Expand(vec1, vec2);

	// display
	cout << "Vector 1: " << vec1.ToString() << endl;
	cout << "Vector 2: " << vec2.ToString() << endl;


	// expanding 2 and 3
	Expand(vec3, vec2);

	// display
	cout << "Vector 2 after expanding with vector 3: " << vec2.ToString() << endl;

	return 0;
}