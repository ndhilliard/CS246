using namespace std;

template <typename T>
// its a ToString()!
void Print(Node<T>* root) {
	cout << "[";
	Node<T>* current = root;
	while (current != nullptr) {
		cout << current->data;
		if (current->next != nullptr) {
			cout << ", "
		}
		current = current->next;
	}
	cout << "]";
};