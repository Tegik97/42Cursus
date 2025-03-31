// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {
	/*	A vector is like a dynamic array in C but no memory management is required
		methods can be used to access or modify vector's memory such as:
		.push_back(x) inserts a new value at the end of the vector
		.clear() wipes the vector
		.size() returns the number of elements
		.at(i) access the i element with range check
		.begin()/.end() first or last element
		Vectors can also be accessed using x[i] but no memory check in this scenario
	*/
	typedef std::vector<Account::t>							  accounts_t;	//accounts_t is a vector of account classes
	typedef std::vector<int>								  ints_t;		//ints_t which is a vector of integers
	/*	std::pair is used to create a simple struct of 2 elements.
		Values inside pair can be accessed using (x.first) and (x.second).
		The next element can be reached using ++(x.first) or ++(x.second).
		elements can be of any type don't have to be of the same type.
	*/
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;	//Declares acc_int_t which is a pair of 2 iterators, one of each account and one for each int

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );	//Calculates the number of elements in amounts[]
	accounts_t				accounts( amounts, amounts + amounts_size );	//Creates a vector of amounts[] elements each value in every account takes the value in amounts[i]
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );	/*	mem_fun_ref calls the function displayStatus() for each element in the accounts vector.
																							arguments are sent to the function as reference not copies of the value in this way 
																							if the function modifies a value it works on the original.
																						*/
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
