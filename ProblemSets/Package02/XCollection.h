#ifndef XCOLLECTION_H
#define XCOLLECTION_H

#include <iostream>
#include <string>
#include "Util.h"

namespace ds
{
	class Collection 
	{
		public:
		virtual void Insert(const T&) = 0;
		virtual void Remove(const T&) = 0;
		virtual void RemoveAll(const T&) = 0;
		virtual bool Contains(const T&) const = 0;
		virtual long Count(const T&) const = 0;
		virtual bool Empty() const = 0;
		virtual long Size() const = 0;
	};
}

#endif
