/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:34:29 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/21 13:34:30 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	printSeparator(std::string str)
{
	std::cout << std::string(40, '=') << std::endl;
	std::cout << "    " << str << std::endl;
	std::cout << std::string(40, '=') << std::endl;
}

int main()
{
	//Test with subject main
	printSeparator("     TEST 1: SUBJECT MAIN");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	//Test with subject main but list not MutantStack
	printSeparator("TEST 2: SUBJECT MAIN WITH LIST");
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}

	//MutantStack with strings
	printSeparator("TEST 3: MUTANTSTACK WITH STRINGS");
	{
		MutantStack<std::string>	mstack;
		
		mstack.push("Hello");
		mstack.push("32");
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push("42");
		mstack.push("Firenze");
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
	}

	//MutantStack with copy constructor
	printSeparator("   TEST 4: COPY CONSTRUCTOR");
	{
		MutantStack<int>	mstack;

		mstack.push(12);
		mstack.push(22);
		mstack.push(32);

		MutantStack<int>	mstackCopy(mstack);

		std::cout << "mstack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << "\nmstackCopy:" << std::endl;
		for (MutantStack<int>::iterator it = mstackCopy.begin(); it != mstackCopy.end(); ++it)
			std::cout << *it << std::endl;

		mstackCopy.push(42);
		std::cout << "\nmstack after mstackCopy.push(42):" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << "\nmstackCopy after mstackCopy.push(42):" << std::endl;
		for (MutantStack<int>::iterator it = mstackCopy.begin(); it != mstackCopy.end(); ++it)
			std::cout << *it << std::endl;
	}

	//Empty stack
	printSeparator("     TEST 5: EMPTY STACK");
	{
		MutantStack<int>	mstack;
		
		std::cout << "Is empty: " << mstack.empty() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "Iteration on empty stack completed" << std::endl;
	}

	//Const iterators
	printSeparator("    TEST 6: CONST ITERATORS");
	{
		MutantStack<int>	mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		const MutantStack<int>&	const_mstack = mstack;

		for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
			std::cout << *it << std::endl;
	}
}
