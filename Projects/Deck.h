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
	private:
		// Friend declaration
		friend class Game;
		Node<Token>* head;
		Node<Token>* tail;
		long size;
		bool extendedDisplay;

		// This method helps retrieve specific Tokens for the View() method
		Node<Token>* GetNodeAtPosition(int position) const {
			if (position < 0 || position >= size) {
				throw std::invalid_argument("Invalid position for View()");
			}
			Node<Token>* current = head;
			for (int i = 0; i < position; i++) {
				current = current->next;
			}
			return current;
		}
		/*
		IsUniform() checks to see if all Tokens in a deck match
		This method is called by burnie in the Game.h file so i had to make it.
		i had to give game.h friend privelages i hope thats ok
		*/
		bool IsUniform() const {
			if (Empty()) {
				return true; // An empty deck can be considered uniform
			}

			Node<Token>* current = head;
			std::string key = current->data.Key(); // Get the key of the first token

			while (current != nullptr) {
				if (current->data.Key() != key) {
					return false; // If any token key differs, the deck is not uniform
				}
				current = current->next;
			}

			return true; // All tokens have the same key
		}
	
	public:
		// task 2
		// default contructor initilizing deck to empty with null heads and tails
		Deck() : head(nullptr), tail(nullptr), size(0), extendedDisplay(false) {} 

		// copy constructor that initializes deck by copying the node from another deck
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

		// assignment operator clears the current deck and copies th4e nodes from another
		Deck& operator=(const Deck& rhs) {
			if (this != &rhs) {
				Clear();
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
			Clear();
		}

		// Task 3
		/*
		Insert method that adds a token to the deck based on specific parameters
		pc: is player controlled insertion. If the pc flag is used then the deck must be empty or the head of the deck must match the token that is being inserted
		gc: is game controlled insertion and allows for any insertion regardless of deck state
		*/
		void Insert(const Token& token, std::string flag) override {
			if (flag == "pc") {
				if (Empty()) { // Deck is empty, insert ball
					Node<Token>* newNode = new Node<Token>(token);
					head = tail = newNode;
				} else { // deck isnt empty check if tokens are equal
					if (token == head->data) { // if token data is equal, insert at top of deck
						Node<Token>* newNode = new Node<Token>(token);
						newNode->next = head;
						head->prev = newNode;
						head = newNode;
					} else {
						throw std::invalid_argument("Insert Failed: Ball types do not match!");
					}
				}
				size++;
			} else if (flag == "gc") { // insert balls regardless of game state (should only be used to initialize game)
				Node<Token>* newNode = new Node<Token>(token);
				newNode->next = head;
				if (head != nullptr) {
					head->prev = newNode;
				} else {
					tail = newNode;
				}
				head = newNode;
				size++;
			} else {
				throw std::invalid_argument("Invalid flag for Insert(): value must be 'pc' or 'gc'");
			}
		}

		// task 4
		/*
		Remove method removes the top most token from the deck.
		throws an error if deck is empty
		*/
		void Remove(std::string flag) override {
			if (Empty()) { // if deck is empty throw error
				throw std::invalid_argument("Remove failed: Cannot remove from empty tube");
			} else {
				// remove top ball and change head pointer
				Node<Token>* temp = head;
				if (head->next != nullptr) {
					head = head->next;
					head->prev = nullptr;
				} else { // only one ball in the deck
					head = nullptr;
					tail = nullptr;
				}
				delete temp;
				size--;
			}
		} 

		//Task 5
		/*
		Return calls the GetNodeAtPosition function that takes the flag input 
		and returns the token at that specific index
		*/
		Token& View(std::string flag) override {
			if (Empty()) { // empty deck throw error
				throw std::invalid_argument("Deck is empty. Nothing to see here");
			}
			int position = std::stoi(flag); // Convert flag to integer for index
			return GetNodeAtPosition(position)->data;
		}

		const Token& View(std::string flag) const override {
			if (Empty()) { // if empty, throw an error
				throw std::invalid_argument("Deck is empty. Nothing to see here");
			}

			// Convert the flag to an integer for index
			int position = std::stoi(flag);
			// Use GetNodeAtPosition to get the required node
			return GetNodeAtPosition(position)->data;
		}

	
		// Task 6
		// Extend method sets whether the items are able to be seen. This is always true.
		void Extend(bool flag) override {
			extendedDisplay = true; 
		}

		// Task 7
		// size method returns the number of tokens currently in deck
		long Size() const override {
			return size;
		}

		// Task 8
		// Empty() checks whether a deck is empty or not
		bool Empty() const override {
			return size == 0;
		}

		// Task 9
		/* Clear() method removes all nodes from the deck and resets
		head, tail and size to default states
		*/
		void Clear() override {

			Node<Token>* current = head;
			while (current != nullptr) {
				Node<Token>* temp = current;
				current = current->next;
				delete temp;
			}

			head = nullptr;
			tail = nullptr;
			size = 0;
		}

		// Task 10
		/*
		info() prints out the rules of the games and how to use 
		specific flags for methods and how they operate 
		*/
		std::string Info() const override {
			std::stringstream out;
			out << "Valid flags for the Insert() method \n";
			out << "'pc'-'player controlled' adds a ball to the top of the deck if and only if the players ball choice matches the current ball in the selected tube or the selected tube is empty. \n";
			out << "'gc'-'game controlled' adds a ball to the top of the deck regardless of if the current state of the deck and balls contained. \n";
			out << "Valid flags for view will include '2', '3', '4', and '5' for their place in the deck, no flag will return the top ball \n";
			out << "there are no flags for the remove or extend methods \n";
			return out.str();
		}

		// Task 11
		// ToString() prints out how the deck currently looks 
		std::string ToString() const override {
			std::stringstream out;
			int totalSlots = 5; // Adjust as needed
			Node<Token>* current = head;
			for (int i = 0; i < totalSlots; i++) {
				if (current != nullptr) {
					out << "[" << current->data.ToString() << "]";
					current = current->next;
				} else {
					out << "[]";
				}
			}
			return out.str();
		}
	};
}
#endif DECK_H
