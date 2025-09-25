#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct Data
{
	int			id;
	std::string	name;
	double		value;

	Data();
	Data(int i, const std::string& n, double v);
};

#endif