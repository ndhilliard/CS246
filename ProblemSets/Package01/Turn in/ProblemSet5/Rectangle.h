#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include <string>
using namespace std;

class Rectangle : public Shape {

private:
	double length;
	double width;

public:

	Rectangle() : length(1), width(1) {}

	Rectangle(const Rectangle& rhs) : length(rhs.length), width(rhs.width) {}

	Rectangle& operator=(const Rectangle& rhs) {
		if (this != &rhs) {
			length = rhs.length;
			width = rhs.width;
		}
		return *this;
	}

	// accessors methods
	double GetLength() const {
		return length;
	}

	double GetWidth() const {
		return width;
	}

	// mutator methods
	void SetLength(double newLength) {
		if (newLength > 0 && newLength >= width) {
			length = newLength;
		}
	}

	void SetWidth(double newWidth) {
		if (newWidth > 0 && newWidth >= width) {
			width = newWidth;
		}
	}

	double Area() const override {
		return length * width;
	}

	double Perimeter() const override {
		return (length * 2) + (width * 2);
	}

	string ToString() const {
		string result;
		for (int i = 0; i < static_cast<int>(length); i++) {
			for(int j = 0; j < static_cast<int>(width); j++) {
				result += "*";
			}
			result += "\n";
		}
		return result;
	}

};

#endif RECTANGLE_H

