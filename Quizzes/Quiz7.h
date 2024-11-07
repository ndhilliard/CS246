template <class K, class V>
bool Contains(const K& key) {
	Node temp = root;

	while (temp != nullptr && temp.data.key(key) = key) {
		temp = temp->next;
	}
	return temp != nullptr;
}