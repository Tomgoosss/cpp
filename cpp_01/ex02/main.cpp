#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	stringREF = "wowoow";
	std::cout
		<< "str = " << &str << "\n"
		<< "ptr = " << stringPTR << "\n"
		<< "ref = " << &stringREF << std::endl;
	std::cout
		<< "str = " << str << "\n"
		<< "ptr = " << *stringPTR << "\n"
		<< "ref = " << stringREF << std::endl;
}