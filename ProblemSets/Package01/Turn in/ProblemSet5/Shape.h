#ifndef SHAPE_H
#define SHAPE_H

class Shape {

public:
	// virtual methods
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;

	// desctructor
	virtual ~Shape() = default;

};
#endif SHAPE_H

