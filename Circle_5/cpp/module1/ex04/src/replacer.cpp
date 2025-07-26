/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:27:53 by mchiaram          #+#    #+#             */
/*   Updated: 2025/07/26 11:27:54 by mchiaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

static int	errorHandling(std::ifstream& infile, std::string filename, std::string s1, std::string s2)
{
	if (!infile)
	{
		std::cerr << filename << ": no such file or permission denied" << std::endl;
		return 0;
	}
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: empty argument" << std::endl;
		return 0;
	}
	return 1;
}

int	replaceInFile(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	infile(filename.c_str());
	std::string		newFilename = filename + ".replace";
	std::string		line;
	size_t			pos;
	bool			found = false;

	if (!errorHandling(infile, filename, s1, s2))
		return 0;

	std::ofstream	outfile(newFilename.c_str());
	if (!outfile)
	{
		std::cerr << "Cannot create " << newFilename << std::endl;
		return 0;
	}

	while (std::getline(infile, line))
	{
		if (s1 != s2)
		{
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				found = true;
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
				pos += s2.length();
			}
		}
		outfile << line << std::endl;
	}

	if (found)
		std::cout << "successfully replaced strings" << std::endl;
	else if (s1 == s2)
		std::cout << s1 << " is equal to " << s2 << ": nothing replaced " << std::endl << "Copied " << filename << " in " << filename << ".replace" << std::endl;
	else
		std::cout << s1 << " not found in " << filename << std::endl << "Copied " << filename << " in " << filename << ".replace" << std::endl;
	return 1;
}
