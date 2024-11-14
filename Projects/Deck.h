#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>
#include "Util.h"
#include "Tools.h"

// task 1
namespace ds {
	class Deck : public Collection {
	
	// task 2
	private:
		Node<Token>* head;
		Node<Token>* tail;
		long size;
		bool extendedDisplay;
		
		// default constructor
		Deck() : head(nullptr), tail(nullptr), size(0), extendedDisplay(false) {} // deck is initially empty

		// copy constructor
		Deck(const Deck& rhs) : head(nullptr), tail(nullptr), size(0), extendedDisplay(rhs.extendedDisplay) {
			head = Copy(rhs.head);

			// updata tail and size
			Node<Token>* current = head;
			while (current != nullptr) {
				tail = current;
				current = current->next;
				size++;
			}
		}

		// assignment operator
		Deck& operator=(const Deck& rhs) {
			if (this != &rhs) {
				Clear(head);
				head = Copy(rhs.head);
				Node<Token>* current = head;
				while (current != nullptr) {
					tail = current;
					current = current->next;
					size++;
				}
				extendedDisplay = rhs.extendedDisplay;
			}
			return *this;
		}

		// Destructor
		~Deck() {
			Clear(head);
		}

		// Task 6
		// Override Extend() method
		void Extend(bool flag) override {
			extendedDisplay = flag;
		}

		// Task 7
		// Override Size() method
		long Size() const override {
			return size;
		}

		// Task 8
		// Override Empty() method 
		bool Empty() const override {
			return size == 0;
		}

		// Task 10
		// Override Info() method
		std::string Info() const override {
			std::stringstream out;
			out << "Valid flags for the Instert() method \n";
			out << "'pc'-'players choice' adds a ball to the top of the deck if and only if the players ball choice matches the current ball in the selected tube or the selected tube is empty. \n";
			out << "'gc'-'games choice' adds a ball to the top of the deck regardless of if the current state of the deck and balls contained. \n";
			out << "there are no flags for the remove or view methods \n";
			return out.str();
		}
	};
}
#endif DECK_H
