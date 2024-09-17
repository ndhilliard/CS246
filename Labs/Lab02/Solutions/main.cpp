#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "DekaTuple.h"
#include "Mask.h"

void RemoveDuplicates(DekaTuple<Mask>& data)
{
	for (int i = 0; i < 10; i++)
	{
		if(data.Count(data.GetValue(i)) > 1)
		{
			data.GetValue(i).Void();
		}
	}
}

int main()
{
    srand(time(nullptr));
    DekaTuple<Mask> tuple;

    std::cout << "Before RemoveDuplicates() Invocation:\n" << tuple << "\n";
    RemoveDuplicates(tuple);
    std::cout << "After RemoveDuplicates() Invocation:\n" << tuple << "\n";
    return 0;
}
