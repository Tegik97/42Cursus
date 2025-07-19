#include <string>
#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	strPtr = &str;
	std::string&	strRef = str;

	std::cout << "string memory address:" << &str << std::endl;
	std::cout << "pointer memory address:" << strPtr << std::endl;
	std::cout << "reference memory address:" << &strRef << std::endl << std::endl;
	std::cout << "string value:" << str << std::endl;
	std::cout << "pointer value:" << *strPtr << std::endl;
	std::cout << "reference value:" << strRef << std::endl;
}