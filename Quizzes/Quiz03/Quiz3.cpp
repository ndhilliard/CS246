// write the definition of the Pop() method of a stack that uses linked list storage. The node pointer is called top.

void Pop(bool flag) {
	if (top != nullptr) {
		Node<T> t = top;
		top = top->next;
		if (top != nullptr) {
			top->prev = nullptr;
		}
		delete t;
	}
}