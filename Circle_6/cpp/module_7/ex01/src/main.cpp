/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:00:45 by mchiaram          #+#    #+#             */
/*   Updated: 2025/10/09 14:26:48 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

/*template<typename T>
void	printValue(const T& value)
{
	std::cout << value << ", ";
}

void	increment(int& n)
{
	n += 1;
}

int main(void)
{
	int		arr[] = {1, 2, 3, 4, 5, 6};
	const char*	arr2[] = {"Firenze", "Bologna", "Roma", "Venezia", "Torino"};

	
	::iter(arr, 6, printValue<int>);
	std::cout << std::endl;
	::iter(arr, 6, increment);
	::iter(arr, 6, printValue<int>);
	std::cout << std::endl;
	::iter(arr2, 5, printValue<const char*>);
	std::cout << std::endl;
}*/

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}
