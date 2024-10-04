#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>
#include "Util.h"

template <class T>
class ArrayList : public Object 
{
	public:
	virtual void Append(const T&) = 0;
	virtual void Insert(const T&,int) = 0;
	virtual void Erase(const T&) = 0;
	virtual void Detach() = 0;
	virtual void Remove(int) = 0;
	virtual int Search(const T&) const = 0;
	virtual bool Contains(const T&) const = 0;
	virtual const T& At(long) const = 0;
	virtual T& At(long) = 0;
	virtual const T& operator[](long) const = 0;
	virtual T& operator[](long) = 0;
	virtual bool Empty() const = 0;
	virtual int Size() const = 0;
	virtual Resize(long) = 0;
};

#endif