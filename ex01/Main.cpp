#include "Phonebook.h"

int main(void)
{
	std::string input;
	phonebook c1;

	while(1){
		std::getline(std::cin, input);
		if(input == "ADD" || input == "add")
			c1.add();
		else if(input == "SEARCH" || input == "search")
			c1.search();
		else if(input == "EXIT" || input == "exit")
			c1.exit();
		else
			std::cout << "only accept | ADD | SEARCH | EXIT |\n";
	}
	
}