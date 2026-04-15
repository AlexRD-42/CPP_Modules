/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:11:31 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/15 14:45:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// ================= CONSTRUCTORS AND DESTRUCTORS =============================
// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	static int	index = 0;

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

void	Account::_displayTimestamp(void)
{
	std::cout << "[" << "19920104_091532" << "] ";
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
	if (initial_deposit <= 0)
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
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal >= _amount || withdrawal <= 0)
	{
		std::cout << ";refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
	return (true);
}

// ================= GETTERS AND SETTERS =============================

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
