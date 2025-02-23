#include "Account.hpp"

// Define static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor: Initializes an account with an initial deposit
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor: Cleans up the account and updates static totals
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Returns the total number of accounts
int Account::getNbAccounts(void){ 
    return (Account::_nbAccounts); 
}

// Returns the total amount across all accounts
int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

// Returns the total number of deposits made across all accounts
int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

// Returns the total number of withdrawals made across all accounts
int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

// Displays overall account information (number of accounts, total amount, total deposits, total withdrawals)
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << 
    "accounts:" << getNbAccounts() << ";" << 
    "total:" << getTotalAmount() << ";" << 
    "deposits:" << getNbDeposits() << ";" << 
    "withdrawals:" << getNbWithdrawals() << 
    std::endl;
}

// Makes a deposit to the account and updates the relevant totals
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << (_amount + deposit) << ";nb_deposits:" << (++_nbDeposits) << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

// Makes a withdrawal from the account and updates the relevant totals
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (_amount < withdrawal) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << (_amount - withdrawal) << ";nb_withdrawals:" << (++_nbWithdrawals) << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
}

// Checks the current amount in the account
int Account::checkAmount(void) const {
    return _amount;
}

// Displays the current status of the account (index, amount, number of deposits, number of withdrawals)
void Account::displayStatus(void) const {
    std::cout << 
    "index:" << _accountIndex << 
    ";amount:" << _amount << 
    ";deposits:" << _nbDeposits << 
    ";withdrawals:" << _nbWithdrawals 
    << std::endl;
}

// Displays the current timestamp in the format [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void) {
    char buffer[20];
    // Get the current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    // Convert the current time point to a time_t value
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    // Convert the time_t value to a tm structure representing local time
    std::tm *now_tm = std::localtime(&now_time);
    // Format the tm structure into a string
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_tm);
    // Print the formatted timestamp
    std::cout << buffer << " ";
}