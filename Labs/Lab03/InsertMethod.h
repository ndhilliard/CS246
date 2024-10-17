#ifndef INSERTMETHOD_H
#define INSERTMETHOD_H

#include "Util.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace ds;

template <typename T>
void InsertList(Node<T>* lhs, Node<T>* rhs, unsigned int idx) {
	if (lhs->data == nullptr || rhs->data == nullptr) {
		return;
	}
	Node<T>* currentlhs = lhs;
	int lhsSize;
	while (currentlhs->next != nullptr && lhsSize < idx) {
		currentlhs->next;
		lhsSize++;
	}

	Node<T>* lhsholder = currentlhs->next;
	rhs->prev = currentlhs;

	Node<T>* rhsholder = rhs;
	while (rhsholder->next != nullptr) {
		rhsholder = rhsholder->next;
	}

	rhsholder->next = lhsholder;
	lhsholde->prev = rhsholder;
}
#endif INSERTMETHOD_H
