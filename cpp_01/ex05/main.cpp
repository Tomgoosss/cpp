#include "Main.hpp"
#include <string>
#include <iostream>
#include <cctype>

int loop(std::string *level)
{
	for (size_t i = 0; i < level->length(); i++)
	{
		(*level)[i] = std::toupper((*level)[i]);
	}
	if ((*level) == "EXIT" || std::cin.eof())
	{
		return 1;
	}
	if((*level) == "HELP" || std::cin.eof())
	{
		std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR) or 'exit' to quit 'help' for help:\nDONT GIVE THE WRONG INPUT I WARN YOU\n";
		return(2);
	}

	return 0;
}

int main()
{
	Harl harl;
	std::string level;

	std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR) or 'exit' to quit 'help' for help\nDONT GIVE THE WRONG INPUT I WARN YOU\n";
	while (1)
	{
		std::cout << "Harls chat: ";
		std::getline(std::cin, level);
		int result = loop(&level);

		if (result == 1)
			return 0;
		else if (result == 0)
			harl.complain(level);
	}

	return 0;
}