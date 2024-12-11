#include "phonebook.h"

class PhoneBook{
	public:

	void add();
	void search();
	void exit();
	
};

class Contact{

};




int main(void)
{
	std::string input;
	PhoneBook c1;

	while(1){
		std::getline(std::cin, input);
		if(input == "ADD")
			c1.add();
		else if(input == "SEARCH")
			c1.search();
		else if(input == "EXIT")
			c1.exit();
		else
			std::cout << "only accept | ADD | SEARCH | EXIT |\n";
	}
	
}