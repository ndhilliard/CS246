#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <initializer_list>
#include <stdexcept>

namespace ds
{
	class Object 
	{
		public:
		virtual std::string ToString() const = 0;

		friend std::ostream& operator<<(std::ostream& out,const Object& obj)
		{
			out << obj.ToString();
			return out;
		}
	};

	template<class T>
	class Array : public Object
	{
		private:
		T* data;
		unsigned long capacity;
		
		public:
		Array() 
		{
			capacity = 30;
			data = new T[capacity];
			
			for(unsigned long i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}
		
		Array(unsigned long cp) : capacity(cp) 
		{
			if(capacity == 0)
			{
				capacity = 30;
			}
			data = new T[capacity];

			for(unsigned long i = 0;i < capacity;i +=1 )
			{
				data[i] = T();
			}
		}

		Array(unsigned long cp, const T& obj) : capacity(cp)
		{
			if(capacity == 0)
			{
				capacity = 30;
			}
			data = new T[capacity];

			for(unsigned long i = 0;i < capacity;i += 1)
			{
				data[i] = obj;
			}
		}

		Array(std::initializer_list<T> lt)
		{
			capacity = lt.size();
			if(capacity == 0)
			{
				throw std::invalid_argument("invalid capacity");
			}
			data = new T[capacity];
			int i = 0;

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
		}

		Array(const Array<T>& obj)
		{
			capacity = obj.capacity;
			data = new T[capacity];

			for(unsigned long i = 0;i < capacity;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(unsigned long i = 0;i < capacity;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		Array<T>& operator=(std::initializer_list<T> lt)
		{
			if(capacity < lt.size())
			{
				throw std::invalid_argument("out of bound");
			}
			capacity = lt.size();
			int i = 0;
			delete[] data;
			data = new T[capacity];

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
			return *this;
		}

		~Array() { delete[] data; } 

		unsigned long Size() const { return capacity; }

		unsigned long Length() const { return capacity; }

		T& operator[](unsigned long idx)
		{
			if(idx >= capacity)
			{
				throw std::invalid_argument("out of bound");
			}
			return data[idx];
		}
	
		const T& operator[](unsigned long idx) const
		{
			if(idx >= capacity)
			{
				throw std::invalid_argument("out of bound");
			}
			return data[idx];
		}

		std::string ToString() const override
		{
			std::stringstream out;

			out << "[";

			for(unsigned long i = 0;i < capacity;i += 1)
			{
				out << data[i];

				if((i + 1) < capacity)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}
	};	
	
	template <class T>
	class Node
	{
		public:
		T data;
		Node<T>* prev;
		Node<T>* next;
		Node() : Node(T()) {}
		Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}

		friend Node<T>* Copy(Node<T>* rt)
		{
			if(rt == nullptr)
			{
				return nullptr;
			}
			Node<T>* hd = new Node(rt->data);
			Node<T>* t = hd, *s = rt;

			while(s->next != nullptr)
			{
				t->next = new Node(s->next->data);
				t->next->prev = t;
				s = s->next;
				t = t->next;
			}
			return hd;
		} 

		friend void Clear(Node<T>*& rt)
		{
			Node<T>* t;
			
			while(rt != nullptr)
			{
				t = rt;
				rt = rt->next;
				delete t;
				t = nullptr;
			}
		}
	};

	template <class K,class V>
	class Pair : public Object
	{
		public:
		K key;
		V value;
		
		Pair() : Pair(K(),V()) {}

		Pair(const K& key,const V& value) : key(key), value(value) {}
		
		Pair(const Pair<K,V>& obj) 
		{
			key = obj.key;
			value = obj.value;
		}

		Pair<K,V>& operator=(const Pair<K,V>& rhs)
		{
			if(this != &rhs)
			{
				  key = rhs.key;
				  value = rhs.value;
			}
			return *this;
		}

		~Pair() {}

		std::string ToString() const override
		{
			std::stringstream out;
			out << "(" << key << "," << value << ")";
			return out.str();
		}
	};

	template <class T>
	class Set 
	{
		private:
		Node<T>* head;
		unsigned long size;

		public:
		Set() : head(nullptr), size(0) {}

		Set(const Set<T>& obj)
		{
			head = Copy(obj.head);
			size = obj.size;
		}

		~Set() { Clear(head); }

		Set<T>& operator=(const Set<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(rhs.head);
				head = Copy(rhs.head);
				size = rhs.size;
			}
			return *this;
		}

		unsigned long Size() const { return size; }

		bool Empty() const { return head == nullptr; }

		bool Contains(const T& item) const 
		{
			Node<T>* t = head;

			while(t != nullptr && t->data != item)
			{
				t = t->next;
			}
			return (t != nullptr);
		}

		void Insert(const T& item)
		{
			Node<T>* t = head;

			while(t != nullptr && t->data != item)
			{
				t = t->next;
			}

			if(t == nullptr)
			{
				if(head == nullptr)
				{
					head = new Node<T>(item);
				}
				else 
				{
					head->prev = new Node<T>(item);
					head->prev->next = head;
					head = head->prev;
				}
				size += 1;
			}
		}

		void Remove(const T& item)
		{
			Node<T>* t = head;

			while(t != nullptr && t->data != item)
			{
				t = t->next;
			}

			if(t != nullptr)
			{
				if(t->prev == nullptr)
				{
					head = t->next;
				}
				else
				{
					t->prev->next = t->next;
				}

				if(t->next != nullptr)
				{
					t->next->prev = t->prev;
				}
				delete t;
				size -= 1;
			}
		}
	};
	
	template <class T>
	class MultiSet 
	{
		private:
		Node<T>* head;
		unsigned long size;

		public:
		MultiSet() : head(nullptr), size(0) {}

		MultiSet(const MultiSet<T>& obj)
		{
			head = Copy(obj.head);
			size = obj.size;
		}

		~MultiSet() { Clear(head); }

		MultiSet<T>& operator=(const MultiSet<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(rhs.head);
				head = Copy(rhs.head);
				size = rhs.size;
			}
			return *this;
		}

		unsigned long Size() const { return size; }

		bool Empty() const { return head == nullptr; }

		bool Contains(const T& item) const 
		{
			Node<T>* t = head;

			while(t != nullptr && t->data != item)
			{
				t = t->next;
			}
			return (t != nullptr);
		}

		unsigned long Count(const T& item) const 
		{
			Node<T>* t = head;
			unsigned long c = 0;

			while(t != nullptr) 
			{
				if(t->data == item)
				{
					c += 1;
				}
				t = t->next;
			}
			return c;
		}

		void Insert(const T& item)
		{
			if(head == nullptr)
			{
				head = new Node<T>(item);
			}
			else 
			{
				head->prev = new Node<T>(item);
				head->prev->next = head;
				head = head->prev;
			}
			size += 1;
		}

		void Remove(const T& item)
		{
			Node<T>* t = head;

			while(t != nullptr && t->data != item)
			{
				t = t->next;
			}

			if(t != nullptr)
			{
				if(t->prev == nullptr)
				{
					head = t->next;
				}
				else
				{
					t->prev->next = t->next;
				}

				if(t->next != nullptr)
				{
					t->next->prev = t->prev;
				}
				delete t;
				size -= 1;
			}
		}

		void RemoveAll(const T& item)
		{
			Node<T>* i = head;
			Node<T>* c = i;

			while(i != nullptr)
			{
				if(i->data != item)
				{
					c->data = i->data;
					c = c->next;
				}
				i = i->next;
			}

			if(c == head)
			{
				head = nullptr;
			}
			else if(c != nullptr)
			{
				c->prev->next = nullptr;

				while(c != nullptr)
				{
					i = c;
					c = c->next;
					size -= 1;
					delete c;
				}
			}
		}
	};
	
	template <class T>
	class Stack 
	{
		private:
		Node<T>* top;

		public:
		Stack() : top(nullptr) {}

		Stack(const Stack<T>& obj)
		{
			top = Copy(obj.top);
		}

		~Stack() { Clear(top); }

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(rhs.top);
				top = Copy(rhs.top);
			}
			return *this;
		}

		bool Empty() const { return top == nullptr; }

		const T& Top() const
		{
			if(top == nullptr)
			{
				throw std::invalid_argument("empty stack");
			}
			return top->data;
		}

		void Push(const T& item)
		{
			if(top == nullptr)
			{
				top = new Node<T>(item);
			}
			else 
			{
				top->prev = new Node<T>(item);
				top->prev->next = top;
				top = top->prev;
			}
		}

		void Pop()
		{
			if(top != nullptr)
			{
				Node<T>* t = top;
				top = top->next;

				if(top != nullptr)
				{
					top->prev = nullptr;
				}
				delete t;
			}
		}
	};
	
	template <class T>
	class Queue 
	{
		private:
		Node<T>* front;
		Node<T>* rear;

		public:
		Queue() : front(nullptr), rear(nullptr) {}

		Queue(const Queue<T>& obj)
		{
			front = Copy(obj.front);
			rear = front;

			if(rear != nullptr)
			{
				while(rear->next != nullptr)
				{
					rear = rear->next;
				}
			}
		}

		~Queue() 
		{
			Clear(front);
			rear = nullptr;	
		}

		Queue<T>& operator=(const Queue<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(rhs.front);
				front = Copy(front.top);
				rear = front;

				if(rear != nullptr)
				{
					while(rear->next != nullptr)
					{
						rear = rear->next;
					}
				}
			}
			return *this;
		}

		bool Empty() const { return front == nullptr; }

		const T& Peek() const
		{
			if(front == nullptr)
			{
				throw std::invalid_argument("empty queue");
			}
			return front->data;
		}

		void Enqueue(const T& item)
		{
			if(rear == nullptr)
			{
				front = new Node<T>(item);
				rear = front;
			}
			else 
			{
				rear->next = new Node<T>(item);
				rear->next->prev = rear;
				rear = rear->next;
			}
		}

		void Dequeue()
		{
			if(front != nullptr)
			{
				Node<T>* t = front;
				front = front->next;

				if(front != nullptr)
				{
					front->prev = nullptr;
				}
				else
				{
					rear = nullptr;
				}
				delete t;
			}
		}
	};
}

#endif
