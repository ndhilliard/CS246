template <class K, class V>
bool Contans(const K& key) {
	Node temp = root;

	while (temp != nullptr && temp->data.key() = key) {
		temp = temp->next;
	}
	return temp != nullptr;
}
