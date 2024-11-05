#include "Util.h"
#include <set>
#include <cctype>
#include <string>

namespace ds {

	bool OneComplete(const Array<string>& data) {

		// create sets
		set<char> letters;
		set<char> digits;

		// checks each string in array
		for (const string& str : data) {
			for (char : str) {
				if (isalpha(ch)) { // if first item is a letter
					letters.insert(tolower(ch)); // insert all letters as lower case
				} else if (isdigit(ch)) { // if first item is a digit
					digits.insert(ch); // insert all
				} else {
					return false;
				}
			}
		}

		bool allLetters = (letters.size() == 26); // check if there are 26 items since its a set
		bool allDigits = (digits.size() == 10); // check if there are 10 items since its a set

		return (allLetters != allDigits); // return true if only one is true
	}
}