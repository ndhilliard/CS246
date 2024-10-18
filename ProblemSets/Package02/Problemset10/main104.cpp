
template <typename T>
long Count(Node<T>* root, const T& value) {
	// initialize count
	long count = 0;
	// create Node to parse through
	Node<T>* current = root;
	while (current != nullptr) {
		if (current->data == value) {
			count++; // if value is found increase count
		}
		current == current->next;
	}
	return count;
};