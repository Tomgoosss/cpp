#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>  
#include <string>  
#include "Contact.h"

class phonebook{
	private:
	Contact _contact[8];
	int current_index;
	public:
	void add();
	void search();
	void exit();
};

#endif