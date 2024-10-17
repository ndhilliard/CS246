#ifndef REMOVEMETHOD_H
#define REMOVEMOTHOD_H

#include "Util.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace ds;

template <typename T>
	void RemoveList(Node<T>*& rt, unsigned int i, unsigned int j) {
		if (rt->data == nullptr) {
			return;
		}

		Node<T>* rtLeft = rt;
		Node<T>* rtRight = rt;

		// move rtleft pointer to the left most index
		while (rtLeft->next != i) {
			rtLeft = rtLeft->next;
		}

		// move rtright index to right most index
		while (rtRight->next != j) {
			Node<T>* tempHolder = rtRight;
			rtRight = rtRight->next;
			delete tempHolder;
			tempHolder = nullptr;
			
		}

		rtLeft->next = rtRight;
		rtRight->prev = rtLeft;

	}

#endif REMOVEMETHOD_H

