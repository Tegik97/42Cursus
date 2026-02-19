#include "Bot.hpp"

int	main(int argc, char** argv)
{
	if (argc < 4)
	{
		std::cerr << "Not enough arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	Bot	bot(argv);

	bot.run();
}