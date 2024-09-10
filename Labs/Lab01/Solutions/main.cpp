#include <iostream>
#include <string>
#include <cctype>

bool IsSentence(const std::string& str)
{
	for(const char i : str)
	{
		if(!isalpha(i) && i != ' ')
		{
			return false;
		}
	}
	return (!str.empty() && isalpha(str[0]));
}

std::string Capitalize(const std::string& str)
{
	if(!IsSentence(str))
	{
		return std::string();
	}

	std::string rstr = str;
	rstr[0] = toupper(rstr[0]);

	for(int i = 1;i < rstr.length();i += 1)
	{
		if(isalpha(rstr[i]) && rstr[i-1] == ' ')
		{
			rstr[i] = toupper(rstr[i]);
		}
		else 
		{
			rstr[i] = tolower(rstr[i]);
		}
	}
	return rstr;
}
	
int main() 
{
	std::string n;

	std::cout << "Enter a sentence: ";
	std::getline(std::cin,n);

	std::cout << n << "\n" << (IsSentence(n)?("is"):("is not")) << " a sentence.\n";

	if(IsSentence(n))
	{
		std::cout << "Capitalized it is:\n" << Capitalize(n) << "\n";
	}
	return 0;
}
