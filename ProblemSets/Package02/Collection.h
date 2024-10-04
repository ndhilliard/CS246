#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <string>
#include "Util.h"

class Collection 
{
	public:
	virtual void Insert(const T&) = 0;
	virtual void Remove(const T&) = 0;
	virtual bool Contains(const T&) const = 0;
	virtual bool Empty() const = 0;
	virtual long Size() const = 0;
};

#endif
