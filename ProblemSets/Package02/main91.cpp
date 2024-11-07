#include "Vector.h"

#include <iostream>
#include <string>
using namespace std;
using namespace ds;

// im getting errors on here and I'm not exactly sure why 
Vector<string> WordBank() {
	Vector<string> words;
	string word;

	cout << "Please enter your string here (type 'stop' to finish): \n";
	while (true) {
		cin >> word;
		if (word == "stop") {
			break;
		}
		words.Append(word);
	}
	return words;
}

int main() {
	Vector<string> wordBank = WordBank();
	
	cout << "Collected words: " << wordBank.ToString() << endl;

	return 0;
}