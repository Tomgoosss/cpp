#include "Phonebook.hpp"

void phonebook::set_current_index(int index){
	current_index = index;
	total_contacts = index;
}

int main(void)
{
	std::string input;
	phonebook c1;
	c1.set_current_index(1);

	
	while(1){
		std::cout << "| ADD | SEARCH | EXIT |\n";
		std::getline(std::cin, input);
		c1.remove_white(input);
		if(input == "ADD" || input == "add")
			c1.add();
		else if(input == "SEARCH" || input == "search")
			c1.search();
		else if(input == "EXIT" || input == "exit")
			c1.exit();
		else
			std::cout << "only accept | ADD | SEARCH | EXIT |\n";
	}

	return(0);
}