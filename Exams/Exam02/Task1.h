#include "Util.h"

namespace ds {
	template <typename T>
	Node<T>* Merge(Array<Node<T>*>& data) {
		if (data.Size() == 0) { // check if input array is empty
			return nullptr;
		}

		// create head, tail and current nodes to traverse array
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
		Node<T>* current = head;

		for (int i = 0; i < data.size(); i++) {
			Node<T>* current = data[i]; // input array data into nodes

			while (current != nullptr) { // move threw current linked list and add elements 
				Node<T>* newNode = new Node<T>(current->next); // create new element with current data

				// if merged list is empty make new head and tail
				if (head == nullptr) {
					head = tail;
					tail = newNode;
				} else { // append new node to merged list and move tail pointer
					tail->next = newNode;
					tail = newNode;
				}

				current = current->next; // move to next 
			}
		}
		return head; // return merged list
	}
}