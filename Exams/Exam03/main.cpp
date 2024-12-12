#include <iostream>
#include <string>
#include "Tools.h"
using namespace std;

// sorry for being late today!

// function definition
long Range(TNode<long>* root) { 
	if (root == nullptr) { // if tree is empty return 0;
		return 0;
	}

	TNode<long>* minNode = root;
	// while mineNode->left isnt null move down the left side tree
	while (minNode->left != nullptr) {
		minNode = minNode->left;
	}

	TNode<long>* maxNode = root;
	// while maxNode isnt null move down the right side of tree
	while (maxNode->right != nullptr) { 
		maxNode = maxNode->right;
	}

	// subtract the 2 values and return
	return maxNode->data - minNode->data;

}

int main()
{
	return 0;
}
