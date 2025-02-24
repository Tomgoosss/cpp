#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void){ 
    return (Account::_nbAccounts); 
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << 
    "accounts:" << getNbAccounts() << ";" << 
    "total:" << getTotalAmount() << ";" << 
    "deposits:" << getNbDeposits() << ";" << 
    "withdrawals:" << getNbWithdrawals() << 
    std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << 
	";p_amount:" << _amount << 
	";deposit:" << deposit << 
	";amount:" << (_amount + deposit) << 
	";nb_deposits:" << (++_nbDeposits) << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (_amount < withdrawal) {
        std::cout << "index:" << _accountIndex << 
		";p_amount:" << _amount << 
		";withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << 
	"index:" << _accountIndex << 
	";p_amount:" << _amount << 
	";withdrawal:" << withdrawal << 
	";amount:" << (_amount - withdrawal) << 
	";nb_withdrawals:" << (++_nbWithdrawals) << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << 
    "index:" << _accountIndex << 
    ";amount:" << _amount << 
    ";deposits:" << _nbDeposits << 
    ";withdrawals:" << _nbWithdrawals 
    << std::endl;
}

void Account::_displayTimestamp(void) {
    char buffer[20];
    std::time_t now_time = std::time(NULL);
    std::tm *now_tm = std::localtime(&now_time);
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
    std::cout << buffer << " ";
}