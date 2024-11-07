
template <typename T>
long Size(Node<T>* root) {
	long count = 0; // initialize count
	Node<T>* current = root; 
	while (Current != nullptr) {
		count++; // increase count per node
		current = current->next; // move to next node if its not nullptr
	}
	return count;
};