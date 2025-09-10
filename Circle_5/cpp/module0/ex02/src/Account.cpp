/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:23:43 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 10:23:44 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex 
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm*	t = std::localtime(&now);

	std::cout << "[" << (t->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << t->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << t->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << t->tm_hour
			<< std::setw(2) << std::setfill('0') << t->tm_min
			<< std::setw(2) << std::setfill('0') << t->tm_sec
			<< "] ";
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previous = _amount;
	_amount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << previous
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	previous = _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << previous
			<< ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal
			<< ";amount:" << (_amount -= withdrawal)
			<< ";nb_withdrawals:" << ++_nbWithdrawals
			<< std::endl;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return true;
}