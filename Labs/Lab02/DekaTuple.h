#ifndef DEKATUPLE_H
#define DEKATUPLE

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Util.h"
using namespace std;

// setting up generic array thing from Object class?
// i feel like i missed a lot while i was gone
template <class T>

// creating class DekaTuple that inherits Object class
class DekaTuple : public ds::Object {

private:

	// generic array that contians 10 elements
	T data[10];

public:

	// default constructor
	DekaTuple() {
		for (int i = 0; i < 10; i++) {
			data[i] = T();
		}
	}
	

	// copy constructor
	DekaTuple(const DekaTuple<t>& rhs)[
		for (int i = 0; i < 10; i++) {
			data[i] = rhs.data[i];
		}
	]

	// overloaded assignment constructor
	DekaTuple<T>& operator=(const DekaTuple<T>& rhs) {
		if (this != rhs) {
			for (int i = 0; i < 10; i++) {
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	// destructor
	~DekaTuple() {}

	// Getvalue method returns data from array
	// at index value
	T& GetValue(int index) {
		if (index < 0 || index >10) {
			throw out_of_range("out of bounds");
		}
		return data[index];
	}

	// constant version of GetValue
	const T& GetValue(int index) const {
		if (index < 0 || index >= 10) {
			throw out_of_range("out of bounds");
		}
		return data[index];
	}

	// Method checks if array at index 
	// contains elements
	bool Contains(const T& value) const {
		for (int i = 0; i < 10; i++) {
			if (data[i] == value) {
				return true;
			}
		}
		return false;
	}

	// Count method counts how many times parameter
	// appears in array
	int Count(const T& value) const {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (data[i] == value) {
				++count;
			}
		}
		return count;
	}


	// overridden ToString method from Object
	// displays elements in array within parenthesis
	string ToString() const override {
		ostringstream out;
		out << "(";
		for (int i = 0; i < 10; i++) {
			out << data[i].ToString();
			if (i < 9) {
				out << ", ";
			}
		}
		out << ")"
			return out.str();
	}

};

#endif