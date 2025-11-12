#include "Server.hpp"
#include "Client.hpp"
#include "InputParse.hpp"
#include <cstdlib>


int		main(int argc, char *argv[]) {
	if (argc != 3)
	{
		std::cout << "Bad input, must be in this form: ./.. <port> <password> !" << std::endl;
		return 1;
	}
	
	int port = std::atoi(argv[1]);
	std::string password = argv[2];
	InputParse::checkInput(port, password);
	
	Server	server(port, password);
	server.run();
}