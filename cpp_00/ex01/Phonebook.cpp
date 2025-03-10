#include "Phonebook.hpp"

void phonebook::add()
{
	std::string fname, lname, nname, fnum, dsecret;
	do {
		std::cout << "first name : ";
		std::getline(std::cin, fname);
	} while (fname.empty());
	do {
		std::cout << "last name : ";
		std::getline(std::cin, lname);
	} while (lname.empty());
	do {
		std::cout << "nickname : ";
		std::getline(std::cin, nname);
	} while (nname.empty());
	do {
		std::cout << "phone number : ";
		std::getline(std::cin, fnum);
	} while (fnum.empty() || fnumcheck(fnum) == 1);
	do {
		std::cout << "darkest secret : ";
		std::getline(std::cin, dsecret);
	} while (dsecret.empty());
	contact[current_index].setfirstname(fname);
	contact[current_index].setlastname(lname);
	contact[current_index].setnickname(nname);
	contact[current_index].setphonenumber(fnum);
	contact[current_index].setdarkestsecret(dsecret);
	std::cout << "contact added on index " << current_index << '\n';
	current_index++;
	if(current_index >= 9)
		current_index = (current_index + 1) % 9;
	if (total_contacts <= 8)
		total_contacts++;
}
int phonebook::fnumcheck(const std::string &fnum)
{
	std::string temp = fnum;
	remove_white(temp);

	if (!std::isdigit(temp[0]) && temp[0] != '+')
	{
		std::cout << "phone number must contain only digits \n";
		return 1;
	}
	for (size_t i = 1; i < temp.length(); i++)
	{

		if (!std::isdigit(temp[i]))
		{
			std::cout << "phone number must contain only digits \n";
			return 1;
		}
	}
	return (0);
}

bool is_space(unsigned char c)
{
	return std::isspace(c);
}

void phonebook::remove_white(std::string &str)
{
	std::string::iterator end_pos = std::remove_if(str.begin(), str.end(), is_space);
	str.erase(end_pos, str.end());
}

std::string phonebook::format(const std::string& str) const
{
    std::string result;
    if (str.length() <= 10) {
        result = str;
        return std::string(10 - result.length(), ' ') + result;
    } else {
        result = str.substr(0, 9) + ".";
        return result;
    }
}

void phonebook::search()
{
    std::string input;
    if (total_contacts == 0) {
        std::cout << "no contacts active";
        return;
    }
    std::cout << " index     | first name | last name  | nick name \n";
    std::cout << "-------------------------------------------------\n";
    for (int i = 1; i < total_contacts; i++) {
        std::cout << " " << i << "         | ";
        std::cout << format(contact[i].getfirstname()) << " | ";
        std::cout << format(contact[i].getlastname()) << " | ";
        std::cout << format(contact[i].getnickname()) << "\n\n";
    }
    while (true) {
        std::cout << " index = ";
        std::getline(std::cin, input);
        if (input.length() == 1 && std::isdigit(input[0])) {
            int index = input[0] - '0';
            if (index > 0 && index < total_contacts) {
                std::cout 
                << std::setw(10) << "index" << " | "
                << std::setw(10) << "first name" << " | "
                << std::setw(10) << "last name" << " | "
                << std::setw(10) << "nick name" << " | "
                << std::setw(10) << "phone num" << " | "
                << std::setw(10) << "secret" << "\n";
                std::cout << "--------------------------------------------------------------------------\n";
                std::cout 
                << std::setw(10) << index << " | "
                << format(contact[index].getfirstname()) << " | "
                << format(contact[index].getlastname()) << " | "
                << format(contact[index].getnickname()) << " | "
                << format(contact[index].getphonenumber()) << " | "
                << format(contact[index].getdarkestsecret()) << "\n\n";
                break;
            }
            else
                std::cout << "Invalid index" << std::endl;

        }
        else 
            std::cout << "Invalid index" << std::endl;
    }
}

void phonebook::exit()
{
    std::cout << "Exiting the program...\n";
    std::exit(0);
}
