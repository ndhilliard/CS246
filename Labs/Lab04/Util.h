#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
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
}

#endif
