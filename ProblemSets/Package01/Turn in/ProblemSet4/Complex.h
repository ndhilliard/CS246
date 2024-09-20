#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;


class Complex {

private:
	double real;
	double imaginary;

public:
	// default constuctor
	Complex() : real(1.0), imaginary(0.0) {}

	// overloaded constuctor that takes 1 parameter and assigns it to real
	// sets imaginary to default 0
	Complex(double r) : real(r), imaginary(0.0) {}

	// overloaded constuctor that takes 2 parameters and assigns them to
	// both real and imaginary
	Complex(double r, double i) : real(r), imaginary(i) {}

	// copy constructor
	Complex(const Complex& rhs) : real(rhs.real), imaginary(rhs.imaginary) {}

	// overloaded assignment operator so
	// that copy constructor works as intended
	Complex& operator=(const Complex& rhs) {
		if (this != &rhs) {
			real = rhs.real;
			imaginary = rhs.imaginary;
		}
		return *this;
	}

	// destructor
	~Complex() {}

	// accessor methods
	// accesses real value
	double GetReal() const {
		return real;
	}

	// accesses imaginary value
	double GetImaginary() const {
		return imaginary;
	}

	// mutator methods
	// sets real value
	void SetReal(double r) {
		real = r;
	}
	// sets imaginary value
	void SetImaginary(double i) {
		imaginary = i;
	}

	string ToString() const {
		ostringstream out;
		out.precision(1);
		out << fixed;

		if (imaginary == 0) {
			out << real;
		}
		else if (real == 0) {
			out << imaginary << "i" << endl;
		} else {
			out << real;

			if (imaginary > 0) {
				out << " + " << imaginary << "i" << endl;
			} else {
				out << " - " << fabs(imaginary) << " i " << endl;
			}
		} 

		return out.str();
	}

	// friend ostream so that ToString works as intended
	friend ostream& operator<<(ostream& out, const Complex& c) {
		out << c.ToString();

		return out;
	}

};

#endif COMPLEX_H