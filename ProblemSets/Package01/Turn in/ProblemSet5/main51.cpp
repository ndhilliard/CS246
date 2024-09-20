#include "Rectangle.h"
#include "Square.h"
#include <iostream>
using namespace std;

int main() {

	Rectangle rec;
	Square squ;

	rec.SetLength(8);
	rec.SetWidth(6);

	squ.SetSide(5);

	cout << "Rectangle:\n" << rec.ToString();
	cout << "Area: " << rec.Area() << ", Perimeter: " << rec.Perimeter() << "\n\n";

	cout << "Square:\n" << squ.ToString();
	cout << "Area: " << squ.Area() << ", Perimeter: " << squ.Perimeter();

	return 0;
 
}

