/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmendo <davmendo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:05:12 by davmendo          #+#    #+#             */
/*   Updated: 2026/04/16 12:51:45 by davmendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
** initialization of the class static variables
** these are shared across all instances of Account
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** prints a timestamp in the format (YYYYMMDD_HHMMSS)
** uses time() and localtime() to retrieve the current system time
** strftime formats the tm struct into a human readable string
*/
void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	struct tm	*t = std::localtime(&now);
	char		buf[18];

	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", t);
	std::cout << "[" << buf << "] ";
}

/* 
** static getters: return the class-wide global totals 
*/
int	Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int	Account::getNbDeposits(void) { return _totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

/*
** displays a global summary: total accounts, amount, deposits, and withdrawals.
** format: accounts:N;total:N;deposits:N;withdrawals:N
*/
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

/*
** constructor with initial deposit: assigns a sequential index via _nbAccounts
** initialization list sets _accountIndex, _amount, _nbDeposits, _nbWithdrawals
** updates the static totals and prints a creation message
*/
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

/*
** destructor: prints a closing message with the index and final amount
*/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

/*
** deposit: adds the value to the amount and updates counters
** prints the previous amount (p_amount), deposited value, and new amount
*/
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

/*
** withdrawal: denied if the balance is insufficient (_amount < withdrawal)
** if denied, prints "withdrawal:refused" and returns false
** if accepted, subtracts from the amount and updates the counters
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return true;
}

/* 
** Returns current amount (const method, does not modify the object) 
*/
int	Account::checkAmount(void) const
{
	return _amount;
}

/*
** displays individual account status: index, amount, deposits, and withdrawals
** const method: called via std::for_each in tests.cpp
*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
