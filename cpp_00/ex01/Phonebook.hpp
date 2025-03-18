#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>  
#include <string>  
#include "Contact.hpp"
#include <algorithm> 
#include <iomanip>


class phonebook{
	private:
		Contact contact[9];
		int total_contacts;
		int current_index;
	public:
		void add();
		void search();
		void exit();
		int fnumcheck(const std::string& fnum);
		void remove_white(std::string &str);
		void set_current_index(int index);
		std::string format(const std::string& str) const;
};

#endif