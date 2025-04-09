#include "Main.hpp"

void Harl::debug(void){
	std::cout 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do !" 
	<< std::endl;
}
void Harl::info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}
void Harl::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}
void Harl::error(void)
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level){
	static bool hasComplainedOnce = false;
	typedef void (Harl::*Fpntr)();

	Fpntr functions[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	std::string msg[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++){
		if(msg[i] == level){
			(this->*functions[i])();
			return;
		}
	}
	
	 if (hasComplainedOnce)
        std::cout << "You just stabbed a dead Harl.....stop stabbing Harl" << std::endl;
    else {
        std::cout << "Harl just died....." << std::endl;
        hasComplainedOnce = true;
    }
}