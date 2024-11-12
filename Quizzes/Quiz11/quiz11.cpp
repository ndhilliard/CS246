/*
 quiz 11
 Write the source code for the get method
 using an array implementation
 */

template <class K, class V>
void Get(const K& key) {
	int i = 0;

	while (i < size && data[i].key() != key) {
		i++;
	}

	if (i == size) {
		if (size == data.length()) {
			throw runtime_error("At capacity");
		} else {
			data[size] = Pair<K, V>(key, V());
			size++;
			return data[size - 1].value();
		}
	} else {
		return data[i].value();
	}
}
