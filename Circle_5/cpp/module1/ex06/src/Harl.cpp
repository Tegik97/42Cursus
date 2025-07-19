#include "Harl.hpp"

Harl::Harl() {}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" \
				<< std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" \
				<< std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." \
			<< std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	
	switch (i){
		case 0:
			(this->*funcs[0])();
			/* fall through */
		case 1:
			(this->*funcs[1])();
			/* fall through */
		case 2:
			(this->*funcs[2])();
			/* fall through */
		case 3:
			(this->*funcs[3])();
		break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}