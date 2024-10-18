
template <typename T>
void Attatch(Node<T>* a, Node<T>* b) {
	if (a == nullptr || b == nullptr) {
		return;
	}

	Node<T>* currentA = a;
	// moves pointer to the end of a
	while (currentA->next != nullptr) {
		currentA = currentA->next;
	}
	// once at the end of a, attaches b to next
	currentA->next = b;
};