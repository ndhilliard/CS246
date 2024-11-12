template <class K, class V)
	void Remove(k& key) {
	Node temp = root;
	while (temp != nullptr && temp->data.key() != key) {
		temp = temp->next;
	}
	if (temp != nullptr) {
		return temp->data.value();
	} else {
		root->prev = Node<Pair<K, V>>(Pair<K, V>(key, V()));
		root->prev->next = root;
		root = root->prev;
		return root->data.value();
	}
}