#ifndef TOOLS_H
#define TOOLS_H

#include <stack>
#include <queue>
#include <set>
#include <map>

template <class T>
class TNode 
{
	public:
	T data;
	TNode<T>* left;
	TNode<T>* right;
	TNode<T>* p;

	TNode(const T& dt) : data(dt), left(nullptr), right(nullptr), p(nullptr) {}
};

template <class T>
class Set 
{
	private:
	std::set<T> content;

	public:
	void Insert(const T& value) { content.insert(value); }
	void Remove(const T& value) { content.erase(value); }
	bool Contains(const T& value) const 
	{ 
		return content.find(value) != content.end();
       	}
	bool Empty() const { return content.empty(); }
	long Size() const { return content.size(); }
};

template <class T>
class MultiSet 
{
	private:
	std::multiset<T> content;

	public:
	void Insert(const T& value) { content.insert(value); }
	void Remove(const T& value) 
	{ 
		content.erase(content.find(value)); 
	}
	void RemoveAll(const T& value) { content.erase(value); }
	bool Contains(const T& value) const 
	{ 
		return content.find(value) != content.end();
       	}
	bool Empty() const { return content.empty(); }
	long Size() const { return content.size(); }
	long Count() const { return content.count(); }
};

template <class T>
class Stack 
{
	private:
	std::stack<T> content;

	public:
	void Push(const T& value) { content.push(value); }
	void Pop() { content.pop(); }
	const T& Top() const { return content.top(); }
	T& Top() { return content.top(); }
	bool Empty() const { return content.empty(); }
};

template <class T>
class Queue
{
	private:
	std::queue<T> content;

	public:
	void Enqueue(const T& value) { content.push(value); }
	void Dequeue() { content.pop(); }
	const T& Peek() const { return content.front(); }
	T& Peek() { return content.front(); }
	bool Empty() const { return content.empty(); }
};

template <class K,class V>
class Map
{
	private:
	std::map<K,V> content;

	public:
	void Put(const K& key, const V& value) 
	{ 
		content.insert(std::pair<K,V>(key,value)); 
	}
	void Remove(const K& key) { content.erase(key); }
	bool Contains(const K& key) const 
	{ 
		return content.find(key) != content.end();
       	}
	bool Empty() const { return content.empty(); }
	long Size() const { return content.size(); }
	const V& Get(const K& key) const { return content.at(key); }
	V& Get(const K& key) { return content.at(key); }
	const V& operator[](const K& key) const 
	{
	       	return content[key]; 
	}
	V& operator[](const K& key) { return content[key]; }
};

#endif
