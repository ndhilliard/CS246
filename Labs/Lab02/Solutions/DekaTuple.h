#ifndef DEKATUPLE_H
#define DEKATUPLE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Util.h"

template <class T>
class DekaTuple : public ds::Object
{
    private:
	    ds::Array<T> data;

    public:
	    DekaTuple() { data = ds::Array<T>(10); }
	    
	    DekaTuple(const DekaTuple& obj) { data = obj.data; }
	    
	    DekaTuple& operator=(const DekaTuple& rhs)
	    {
		    if (this != &rhs) { data = rhs.data; }
		    return *this;
	    }
	    
	    ~DekaTuple() {}
	    
	    T& GetValue(int idx)
	    {
		    if (idx >= 0 && idx < 10) { return data[idx]; }
		    throw std::invalid_argument("out of bound");
	    }
	    
	    const T& GetValue(int idx) const
	    {
		    if (idx >= 0 && idx < 10) { return data[idx]; }
		    throw std::invalid_argument("out of bound");
	    }
	    
	    bool Contains(const T& value) const
	    {
		    for (int i = 0; i < 10; i += 1)
		    {
			    if (data[i] == value)
			    {
				    return true;
			    }
		    }
		    return false;
	    }
	    
	    int Count(const T& value) const
	    {
		    int count = 0;

		    for (int i = 0; i < 10; i += 1)
		    {
			    if (data[i] == value)
			    {
				    count += 1;
			    }
		    }
		    return count;
	    }
	    
	    std::string ToString() const override
	    {
		    std::string rslt = data.ToString();
		    rslt = "(" + rslt.substr(1,rslt.length()-2) + ")";
		    return rslt;
	    }
};

#endif 
