#include <iostream>
using namespace std;

// function prototype
void GetNumbers(int arr[], int size);
double GetAverage(const int arr[], int size);

int main() {
	
	// variables
	const int SIZE = 10;
	int numbers[SIZE];
	double avg;

	// function call that prompts user
	// to input numbers into array
	GetNumbers(numbers, SIZE);

	// call function to calculate average
	avg = GetAverage(numbers, SIZE);

	// output results from function
	cout << "The average of your numbers is: " << avg << endl;

	return 0;
}

// function definitions
// for loop prompts user to into numbers into a size 10 array
void GetNumbers(int arr[], int size) {

	// for loop prompts user to into numbers into a size 10 array
	for (int i = 0; i < size; i++) {
		cout << "Please enter the value for element " << i + 1 << ": ";
		cin >> arr[i];
	}

}

// function takes the numbers from array and averages them
double GetAverage(const int arr[], int size) {

	// variable
	int sum = 0;

	// for loop that adds the numbers in array
	// and stores them into sum variable
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	//returns average from array
	return sum / size;
}