/*
 quiz 10
 write the source code for the remove method
 using an array implementation
 */

template <class K, class V>
void Removal(const K& key, const V& value) {
	int i = 0;
	while (i < size && data[i].key != key) {
		i++;
	}
	if (i != size) {
		size--;
		while (i < size) {
			data[i] = data[i + 1];
			i++;
		}
	}
}
