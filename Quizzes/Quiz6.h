template <class K, class V>
void Put(const K& key, const V& value) {

	if (root == nullptr) {
		root = new Node<Pair<K,V>(Pair<K,V>(key, value);
	} else {
		Node temp = root;
		while (temp != nullptr && temp->data.key() != key) {
			temp = t->next;
		}
	}

	if (temp == nullptr) {
		root->prev = new Node<Pair<K, V>(Pair<K, V>(key, value);
		root->prev->next = root;
		root = root->prev;
	} else {
		temp->data.value() = value;
	}
}
