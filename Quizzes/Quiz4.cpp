// Write the function named DistinctDigits() that takes an integer parameter and returns the number
// of distinct digits in the parameter if the parameter is positive.
// otherwise it returns 0;
#include <set>
using namespace std;

int DistinctDigits(int value) {

	if (value <= 0) {
		return 0;
	}

	set<int> digits;

	while (value > 0) {
		int x = value % 10;
		digits.insert(x);
		value =  value / 10;
	}
	return digits.size();
}