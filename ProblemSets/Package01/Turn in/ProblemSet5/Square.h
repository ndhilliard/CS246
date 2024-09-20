#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"


class Square : public Rectangle {

public:
	Square() : Rectangle() {}

	Square(const Square& rhs) : Rectangle(rhs) {}

	Square& operator=(const Square& rhs) {
		Rectangle::operator=(rhs);
		return *this;
	}

	double GetLength() const = delete;
	double GetWidth() const = delete;
	void SetLength(double) = delete;
	void SetWidth(double) = delete;

	double GetSide() const {
		return Rectangle::GetLength();
	}

	void SetSide(double side) {
		if (side > 0) {
			Rectangle::SetLength(side);
			Rectangle::SetWidth(side);
		}
	}

};

#endif SQUARE_H
