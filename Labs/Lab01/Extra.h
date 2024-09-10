#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
using namespace std;

class Line {
private:
	int value;

public: 

	// default constructor
	Line() : value(1) {}

	// copy constructor
	Line(const Line& other) : value(other.value) {}

	// accessor function
	int GetLength() const {
		return value;
	}

	// mutator function
	void SetLength(int newValue) {
		if (newValue > 0) {
			value = newValue;
		}
	}

	// function takes value and prints '*'s = to value
	string GetLine() const {
		return string(value, '*');
	}

	// takes number of '*'s and sets to int value
	void SetLine(const string& line) {
		bool allstars = true;
		for (char c : line) {
			if (c != '*') {
				allstars = false;
				break;
			}
		}
		if (allstars) {
			value = line.length();
		}
	}

};

#endif // EXTRA_H
