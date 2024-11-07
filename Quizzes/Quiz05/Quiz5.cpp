// Write a void function named Padding() whose header is 
// void Padding(Node<int>* rt, int a, int b)
// that attaches a node whose data equals a to the head of rt and attaches a Node whose data equals b to the tail of rt
// hint: use a Set object continually divide the number by 10 unti it becomes 0;

void Padding(Node<int>* rt, int a int b) {
	Node<int>* current = rt;

	Node<int>* newNode = new Node(a);
	newNode->next = rt;
	rt = newNode;

	while (current->next != nullptr) {
		current = current->next;
	}

	Node<int>* newNode = new Node(b);
	current->next = newNode;

	return;
}