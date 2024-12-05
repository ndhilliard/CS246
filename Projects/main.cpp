#include "Game.h"
#include <cctype>

int main()
{
	Token t;
	Deck d;
	Game g;
	bool o = true;
	char ch;
	std::string str;
	int value;

	std::cout << "Deck options\n";

	while(true)
	{
		std::cout << "\nI. Perform an insert\n";
		std::cout << "R. Perform a removal\n";
		std::cout << "V. Perform a view\n";
		std::cout << "E. Change display\n";
		std::cout << "S. Check size\n";
		std::cout << "P. Check emptiness\n";
		std::cout << "C. Clear deck\n";
		std::cout << "H. Retrieve deck information\n";
		std::cout << "D. Display deck\n";
		std::cout << "Q. Quit program\n";
		std::cout << "Enter choice: ";
		std::cin >> ch;
		ch = tolower(ch);
		std::cout << "\n";

		if(ch == 'i')
		{
			std::cout << "Enter the token's key: ";
			std::cin >> str;
			std::cout << "Enter the token's value: ";
			std::cin >> value;

			t = Token(str,value);
			std::cout << "Token: " << t << "\n";

			std::cout << "Enter an insert command: ";
			std::cin >> str;

			d.Insert(t,str);
			std::cout << "The insertion was performed\n";
		}
		else if(ch == 'r')
		{
			std::cout << "Enter a remove command: ";
			std::cin >> str;
			d.Remove(str);
			std::cout << "The removal was performed\n";
		}
		else if(ch == 'v')
		{
			std::cout << "Enter a view command: ";
			std::cin >> str;

			try 
			{
				t = d.View(str);
				std::cout << "The view retrieved the token " << t << "\n";
			}
			catch(...)
			{
				std::cout << "An error occurred\n";
			}
		}
		else if(ch == 'e')
		{
			o = !o;
			d.Extend(o);
			std::cout << "The display has been changed\n";
		}
		else if(ch == 's')
		{
			std::cout << "The deck has a size of " << d.Size() << "\n";
		}
		else if(ch == 'p')
		{
			std::cout << "The deck " << ((d.Empty())?("is"):("is not")) << " empty\n";
		}
		else if(ch == 'c')
		{
			d.Clear();
			std::cout << "The deck has been emptied\n";
		}
		else if(ch == 'h')
		{
			std::cout << "Deck Information:\n" << d.Info()<< "\n";
		}
		else if(ch == 'd') 
		{
			std::cout << d << "\n";
		}
		else if(ch == 'q')
		{
			break;
		}
		else 
		{
			std::cout << "Invalid selection\n";
		}	
	}

	std::cout << "\nTime To Play The Game\n";

	g.Initialize();

	while(!g.Completed())
	{
		std::cout << "\n" << g << "\n";
		std::cout << "M. Move\n";
		std::cout << "U. Undo\n";
		std::cout << "H. Help\n";
		std::cout << "Q. Quit\n";
		std::cout << "Enter choice: ";
		std::cin >> ch;
		ch = tolower(ch);
		std::cout << "\n";

		if(ch == 'm')
		{
			std::cout << "Enter a move command: ";
			std::cin >> str;
			g.Move(str);
		}
		else if(ch == 'u')
		{
			std::cout << "The undo " << ((g.Undo())?("was"):("was not")) << " perfomed.\n";
		}
		else if(ch == 'h')
		{
			std::cout << g.Info() << "\n";
		}
		else if(ch == 'q')
		{
			break;
		}
		else 
		{
			std::cout << "Invalid choice\n";
		}
		std::cout << "Current State: " << g.State() << "\n";
	}

	return 0;
}
