
template <typename T>
int Maximum(Node<int>* root) {
	if (root == nullptr) {
		return 0;
	}

	int maxValue = root->data;
	Node<int>* current = root;
	while (current != nullptr) {
		if (current->data > maxValue) {
			maxValue = current->data;
		}
		current = current->next
	}
	return maxvalue;
};