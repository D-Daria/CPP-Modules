#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>


//initialize private static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//display current time
void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);// get time now
    std::tm* now = std::localtime(&t);

    std::cout << "[" 
	<< (now->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << now->tm_mday << '_'
	<< std::setw(2) << std::setfill('0') << now->tm_hour
	<< std::setw(2) << std::setfill('0') << now->tm_min
	<< std::setw(2) << std::setfill('0') << now->tm_sec
	<< "] ";
}

//return static variablies from static member functions //?
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void) 
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

//Constructor without arguments
Account::Account(){};

//Contructor
//init all values
/*
	amount - initial_deposit
*/
Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created";
	std::cout << std::endl;
}

//Destructor
Account::~Account()
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "closed";
	std::cout << std::endl;
};


void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout 
			  << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";"
			  << "deposit:" << deposit << ";";

	_amount += deposit;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_nbDeposits += 1;
	std::cout
			 << "amount:" << checkAmount() << ";"
			 << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";";
	if (checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	std::cout
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << checkAmount() << ";"
		<< "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int	Account::checkAmount(void) const // <== The implicit "this" pointer is const-qualified
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << checkAmount() << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
