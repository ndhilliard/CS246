template <class K, class V>
void Remove(const K& key) {
	Node temp = root;
	while (temp != nullptr && temp->data.key != key) {
		temp = temp->next;
	}
	if (temp == nullptr) {
		if (temp->prev == nullptr) {
			root = temp->next;
		} else {
			temp->prev->next = temp->next;
		}
		if (temp->next != nullptr) {
			temp->next->prev = temp->prev;
		}
		delete T;
	}
}