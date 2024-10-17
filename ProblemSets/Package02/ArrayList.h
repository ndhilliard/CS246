#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>
#include "Util.h"

namespace ds
{
	template <class T>
	class ArrayList : public Object 
	{
		public:
		virtual void Append(const T&) = 0;
		virtual void InsertAt(const T&,long) = 0;
		virtual void Erase(const T&) = 0;
		virtual void Detach() = 0;
		virtual void Remove(long) = 0;
		virtual long Search(const T&) const = 0;
		virtual bool Contains(const T&) const = 0;
		virtual const T& At(long) const = 0;
		virtual T& At(long) = 0;
		virtual const T& operator[](long) const = 0;
		virtual T& operator[](long) = 0;
		virtual bool Empty() const = 0;
		virtual long Size() const = 0;
		virtual void Resize(long) = 0;
	};
}
#endif
