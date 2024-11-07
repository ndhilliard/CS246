

template <typename T>
bool Distinct(Node<T>* root) {
	// creating new node to parse through.
	Node<T>* current = root;
	while (current != nulltptr) {
		// creating 'Next' node to compare if data-next == current data
		Node<T>* next = current->next;
		while (next != nullptr) {
			if (next->data == current->data) {
				return faslse; //if duplipcate found return false
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return true;
};