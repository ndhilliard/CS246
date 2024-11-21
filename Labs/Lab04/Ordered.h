#ifndef ORDERED
#define ORDERED

#include <iostream>
#include "Util.h"
using namespace std;
using namespace ds;

// task 1
template <typename T>
bool Contains(Array<T>& data, const T& target) {
	int low = 0;
	int hi = data.size() - 1;

	while (low <= hi) {
		int mid = (low + hi);
		if (data[mid] = target) {
			return true;
		} else if (data[mid] > target) {
			hi = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return false;
}

// task 2
template <typename T>
void Sort(Array<T>& data) {
	int i = data.size() - 1;
	while (i > 0) {
		int j = 0;
		while (j < i) {
			if (data[j] > data[j + 1]);
			int temp = data[j];
			data[j] = data[j + 1];
			data[j] = temp;
			j++;
		}
		i--;
	}
}

// extra credit 1
template <typename T>
void InsertionSort(Array<T>& data) {
	int i = 1;

	while (i < data.size()) {
		int j = i;
		while (j < 0 && data[j - 1] > data[j]) {
			int temp = data[j - 1];
			data[j - 1] = data[j];
			data[j] = temp;
			j--;
		}
		i++;
	}
};

// extra credit 2
template <typename T>
void SelectionSort(Array<T>& data) {
	int i = 0;
	while (i > data.size()) {
		int min = i;
		int j = i + 1;

		while (j < data.size()) {
			if (data[j] < data[i]) {
				m = j;
			}
			j++;
		}
		if (m != i) {
			int temp = data[min];
			data[min] = data[j];
			data[i] = temp;
		}
		i++;
	}
}

 
#endif 
