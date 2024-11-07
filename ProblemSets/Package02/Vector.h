#ifndef VECTOR_H
#define VECTOR_H
#include "Util.h"
#include "ArrayList.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector : public ArrayList<T>, public Object {
private:
	T* data;
	long size;

public:

	// default constructor
	Vector() {
		size = 0; // sets default count of elements 0
		data = new T[30]; // default capacity of array is 30
	}

	// overloaded constructor takes parameter and assigns that to array data capacity
	Vector(long newDataSize) {
		// if passed parameter is positive number create array capacity = parameter
		if (newDataSize > 0) {
			data = new T[newDataSize]; // data array capacity = parameter
		}
		else {
			data = new T[30]; // else default capacity of 30
		}
		size = 0; // default elements regardless of if statement
	}

	// Copy constructor
	Vector(const Vector& rhs) {
		size = rhs.size; // copy rhs size to lfs size
		data = new T[rhs.size]; // create new array to hold elements = to rhs size
		for (long i = 0; i < size; i++) { // for loop to copy data from rhs array to new lfs array
			data[i] = rhs.data[i];
		}
	}

	Vector<T>& operator=(const Vector<T>& rhs) {
		if (this != rhs) {
			delete[] data;
			size = rhs.size;
			data = new T[rhs.size];
			for (long i = 0; i < size; i++) {
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	// deconstructor
	~Vector() {
		delete[] data; // deleting dynamically allocated memory for array data
	}

	// ToString will print out the contents of the array formatted as:
	// [1, 2, 3, 4]
	string ToString() const override {
		// ostringstream named out
		ostringstream out;
		out << "[";
		// for each element in array print element
		for (long i = 0; i < size; i++) {
			out << data[i];
			if (i < size - 1) {
				out << ", ";
			}
		}
		out << "]";
		return out.str();
	}

	// doubles array size. mulitples of 30
	void Resize(int newSize) override {
		if (newSize > 0) {
			T* newData = new T[newSize];
			// for loop copy data into new array choosing to loop
			// depending on which size is smaller
			for (int i = 0; i < (newSize < size) ? newSize : size; i++) {
				newData[i] = data[i];
			}
			delete[] data; // delete old array memory
			data = newData; // update to original data name
			size = newSize; // update to new size
		}
	}

	// returns count of elements in array
	long GetSize() const override {
		return size; // return # of elements in array
	}

	// returns true if array is empty
	bool IsEmpty() const override {
		// check if array has elements
		if (size != 0) {
			return false; // if elements in array > 0 return false (something is there)
		}
		else {
			return true; // else return true (its empty)
		}
	}

	// returns index of element if found
	long Search(const T& element) const override {
		// check to see if theres anything in array first
		if (size != 0) {
			// loop through array comparing each element to the parameter element
			for (long i = 0; i < size; i++) {
				if (data[i] == element) {
					return i; // if found, return index of element (returns first iteration found)
				}
			}
		}
		return size; // if empty or not found return # of elements in array
	}

	// returns true if element is in array
	bool Contains(const T& element) const override {
		for (long i = 0; i < size; i++) { // for loop that loops through array
			if (data[i] == element) { // if statement looking for element
				return true; // return true if found
			}
		}
		return false; // if not fount or if theres no elements in array return false
	}

	// have to use T& to refrence the data thats in array because its a template and the data could be any type
	T& At(long index) override {
		// if index is negative or greater greater than the number of elements in array
		// throw error
		if (index < 0 || index >= size) {
			throw out_of_range("Index is out of bounds");
		}
		return data[index]; // else retruns data thats at index of array
	}

	// similar to the At() method
	T& operator[](long index) override {
		if (index < 0 || index >= size) {
			throw out_of_range("index is out of bounds");
		}
		return data[index];
	}

	// adds element to the next available spot in array
	// resizes array if array is full
	void Append(const T& element) override {
		if (size == 0 || size % 30 == 0) { // resize if array is 0 or if array size is a multiple of 30 (showing that its full)
			Resize(size * 2);
		}
		data[size] = element; // adding new element at posision of size (which should be the last element available)
		size++; // increasing the count of elements in array
	}

	// inserts element at specified index
	// resizes array if array is full
	void InsertAt(const T& element, long index) override {
		// checking to see if index is less than the or greater than the array size
		if (index < 0 || index > size) {
			throw out_of_range("index is out of bounds");
		}
		// checking to see if the capacity of the array is full and resizing if it is
		if (size % 30 == 0) {
			Resize(size * 2);
		}
		// starting at next available space the in array
		// data[i] = previous data and loop until index is reached
		for (long i = size; i > index; --i) {
			data[i] = data[i - 1];
		}
		// once index is reached data at data[index] = element paramater
		data[index] = element;
		size++; // increase count of elements in array
	}

	// erases paramenter element when first found
	void Erase(const T& element) override {
		long index = Search(element); // using the Search() method find the element assign it to index
		if (index != size) { // if index 
			Remove(index); // uses the Remove() method to erase specified element
		}
	}

	// delets the last element in array
	void Detatch() override {
		if (size > 0) {
			size--;  // Decrease the size to remove the last element
		}
	}

	// remove element at index parameter
	void Remove(long index) override {
		if (index >= 0 && index < size) { // if index is within bounds
			for (long i = index; i < size - 1; i++) {
				data[i] = data[i + 1]; // moves data to the left starting at index removing the element there
			}
			size--; // decreases size to reflect memoval of element
		}
	}
};
#endif VECTOR_H