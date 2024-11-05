#include "Util.h"

void Push(const T& item) {
	// check if stack is full
	if (top >= data.size() - 1) { // if full return
		return;
	} else { // else increase stack count and top spot = item
		top++;
		data[top] = item;
	}
	return;
}

void Pop(bool flag) {
	if (flag = true) { // if parameter is true
		if (top >= 0) { // and if stack is not empty
			top--; // remove top most item
		}
	} else {
		if (top >= 1) { // if parameter false
			data[top - 1] = data[top]; // removes item below top (top - 1 = top)
			top--; // decrease stack count
		}
	}
	return;
}

const T& Top(bool flag) cosnt {
	if (flag = true) { // if flag is true
		if (top >= 0) { // and if stack is not empty
			return data[top]; // return item data
		} else { // else throw error
			throw "invalid request";
		}
	} else { // if flag is false
		if (top >= 1) { // and if theres at least 2 items in stack
			return data[top - 1]; // return item below top
		} else {
			throw "invalid request"; // else throw error
		}
	}
	return;
}

bool Empty() const {
	return (top < 0); // return true if stack is empty
}