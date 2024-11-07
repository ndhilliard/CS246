#ifndef STATICSET_H
#define STATICSET_H

#include "util.h"
#include "Collection.h"
using namespace ds;

template <typename T>
class StaticSet : public Collection(T), public Object{
private:
	Array<T> data;
	long size;

public:
	// default constructor
	StaticSet() {
		size = 0;
		data = new T[30]
	}

	// overloaded constructor takes long int parameter for data size
	StaticSet(long newDataSize) {
		if (newDataSize > 0) {
			data = new T[newSize];
		} else {
			data = new T[30];
		}
		size = 0;
	}

	// Copy constructor
	StaticSet(const StaticSet& rhs) {
		size = rhs.size; // copy rhs size to lfs size
		data = new T[rhs.size]; // create new array to hold elements = to rhs size
		for (long i = 0; i < size; i++) { // for loop to copy data from rhs array to new lfs array
			data[i] = rhs.data[i];
		}
	}

	StaticSet<T>& operator=(const StaticSet<T>& rhs) {
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
	~StaticSet() {
		delete[] data; // deleting dynamically allocated memory for array data
	}

	// ToString will print out the contents of the array formatted as:
	// {1, 2, 3, 4}
	string ToString() const override {
		// ostringstream named out
		ostringstream out;
		out << "{";
		// for each element in array print element
		for (long i = 0; i < size; i++) {
			out << data[i];
			if (i < size - 1) {
				out << ", ";
			}
		}
		out << "}";
		return out.str();
	}

	// returns size
	long Size() const override {
		return size;
	}

	// returns true if size is 0
	bool Empty() const override {
		return size == 0;
	}

	// searches array for specific element
	bool Contains(const T& element) const override {
		for (long i = 0; i < size < i++) {
			if (data[i] == element) {
				return true;
			}
		}
		return false;
	}

	// insertion method
	void Insert(const T& element) override {
		if (!contains(element)) {
			data[size] = element;
			size++;
		}
	}

	void Remove(const T& element) override {
		for (long i < 0; i < size; i++) {
			if (data[i] == element) {
				for (long j = i; j < size - 1; j++) {
					data[j] = data[j + 1];
				}
				size--;
				break;
			}
		}
	}
};
#endif STATICSET_H
