/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:11:31 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 09:59:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

// static member definitions
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ================= CONSTRUCTORS AND DESTRUCTORS =============================
// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	static int	index = 0;	// So accIndex doesnt get affected by account closures

	_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

// std::cout << "[19920104_091532] " for diff
void Account::_displayTimestamp(void)
{
	time_t		now = time(NULL);
	struct tm	*loc_time = localtime(&now);

	std::cout << "[" << (loc_time->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << loc_time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << loc_time->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << loc_time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << loc_time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << loc_time->tm_sec << "] ";
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// ================= LOGS =============================
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
// [19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
void	Account::makeDeposit(int initial_deposit)
{
	_displayTimestamp();
	if (initial_deposit <= 0)	// because apparently unsigned integers do not exist
		return ;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << initial_deposit << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal >= _amount || withdrawal <= 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

// ================= GETTERS AND SETTERS >:) =============================

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}
