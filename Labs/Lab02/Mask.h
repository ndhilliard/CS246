#ifndef MASK_H
#define MASK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Util.h"

class Mask : public ds::Object
{
	private:
	short value;

	public:
	Mask() { value = (rand() % 9 + 1); }

	Mask(const Mask& obj) { *this = obj; }

	Mask& operator=(const Mask& rhs)
	{
		if(this != &rhs) { value = rhs.value; }
		return *this;
	}

	~Mask() {}

	void Void() { value = 0; }

	bool IsVoid() const { return (value == 0); }

	std::string ToString() const override { return ((value == 0)?("X"):("O")); }

	friend bool operator==(const Mask& lhs,const Mask& rhs)
	{
		return (lhs.value == rhs.value);
	}

	friend bool operator!=(const Mask& lhs,const Mask& rhs)
	{
		return !(lhs == rhs);
	}
};

#endif
