#include "Util.h"
#include <iostream>

namespace ds {
	template <typename T>
	void RemoveDuplipcate(Node<T>*& data) {
		if (data == nullptr) { // if list is empty do nothing
			return;
		}

		Node<T>* current = data;

		// run through each node till nullptr is reached
		while (current != nullptr && current->next != nullptr) {
			Node<T>* check = current;

			while (current->next != nullptr) { // looping to look for duplicates till null is found
				if (check->next->data == current->data) { // dupilicate found
					Node<T>* temp = check->next; // move data to be deleted
					check->next = check->next->next; // move check pointer up 
					delete temp; // free up memory
				} else {
					check = check->next; // move the check pointer
				}
			}
			current = current->next; // move current up
		}
	}
}