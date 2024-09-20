#include "Complex.h"
#include <iostream>
using namespace std;



int main() {

	// creating objects
	Complex a(5.0); // purely real numbers
	Complex b(0.0, 3.0); // purely imaginary
	Complex c(4.0, -2.0); // complex with imaginary part
	Complex d(1.0, 1.0); // mixed
	Complex e(2.0, 3.0); // mixed
	Complex f(-3.0, -5.0); // mixed

	// displaying objects
	cout << "a: " << a << "b: " << b << "c: " << c << "d: " << d <<
		"e: " << e << "f: " << f;

	// creating 4 more objects with operations
	// adding objects
	Complex g = Complex(a.GetReal() + b.GetReal(), a.GetImaginary() + b.GetImaginary());

	// subtracting objects
	Complex h = Complex(c.GetReal() - e.GetReal(), c.GetImaginary() - e.GetImaginary());
	
	// multipling objects
	Complex x = Complex(
		e.GetReal() * f.GetReal() - e.GetImaginary() * f.GetImaginary(),
		e.GetReal() * f.GetImaginary() + e.GetImaginary() * f.GetReal());
	
	// dividing objects
	double denominator = f.GetReal() * f.GetReal() + f.GetImaginary() * f.GetImaginary();
	Complex y = Complex(
		(a.GetReal() * f.GetReal() + a.GetImaginary() * f.GetImaginary()) / denominator,
		(a.GetImaginary() * f.GetReal() - a.GetReal() * f.GetImaginary()) / denominator);

	// displaying new objects
	cout << "g (a + b): " << g << "h (c - e): " << h << "x (e * f): " << x << "y (a / f): " << y;


	return 0;
}
