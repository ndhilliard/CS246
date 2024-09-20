#include <iostream>
#include <string>
using namespace std;

// function prototype
void Populate(Entry*);
void Print(Entry*);
void KillEntry(Entry*&);


// creating struct
struct Entry {
	// struct variables
	string category;
	double* values;
	int count;
};

// creating entry object
Entry* NewEntry() {

	// creating variables
	string category;
	int count;

	// user prompt
	cout << "Please enter a name for the categroy: ";
	cin >> category;

	cout << "Please enter a number for the count of values (between 1 and 20)";
	cin >> count;

	if (count < 1 || count >20) {
		cout << "Invalid count value. Count must be between 1 and 20.";
		return nullptr;
	}

	Entry* entry = new Entry;
	entry->category = category;
	entry->count = count;
	entry->values = new double[count];

	return entry;
}

int main() {

	Entry* entry = NewEntry();

	Populate(entry);
	Print(entry);
	KillEntry(entry);

	return 0;
}

// function definition

void Populate(Entry* entry) {
	if (entry == nullptr) {
		return;
	}

	// user prompt to enter values
	// will keep prompting until input is a positive number
	for (int i = 0; i < entry->count; i++) {
		double value;
		do {
			cout << "Enter value for position " << i << ": ";
			cin >> value;
			if (value < 0) {
				cout << "Invalid value. Must be a positive integer." << endl;
			}
		} while (value < 0);
		
		entry->values[i] = value;
	}
}

void Print(Entry* entry) {
	if (entry == nullptr) {
		return;
	}

	cout << "Category: " << entry->category << endl;
	for (int i = 0; i < entry->count; i++) {
		cout << "Value " << (i + 1) << ": " << entry->values[i] << endl;
	}
}

void KillEntry(Entry*& entry) {
	if (entry == nullptr) {
		return;
	}

	delete[] entry->values;
	delete entry;
	entry = nullptr;
}
