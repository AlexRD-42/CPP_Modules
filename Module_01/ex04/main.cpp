/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:14:49 by adeimlin          #+#    #+#             */
/*   Updated: 2026/04/16 14:54:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

static
int	stt_read_file(const char *str, std::string &out)
{
	std::ifstream		file(str);
    std::stringstream	buffer;

	if (file.is_open() == false)
	{
		std::cerr << "Failed to open file\n";
		return (-1);
	}
	buffer << file.rdbuf();
	out = buffer.str();
	return (0);
}

static
void	stt_replace(std::string &file_string, std::string &s1, std::string &s2)
{
	size_t	index;

	if (s1.empty())
		return ;
	index = file_string.find(s1, 0);
	while (index != std::string::npos)
	{
		file_string.erase(index, s1.length());
		file_string.insert(index, s2);
		index = file_string.find(s1, index);
	}
}

int main(int argc, char **argv)
{
	std::string		s1;
	std::string		s2;
	std::string		filename;
	std::string		file_string;
	std::ofstream	output;

	if (argc != 4)
	{
		std::cerr << "Invalid argument count\n";
		return (1);
	}
	filename = argv[1];
	filename += ".replace";
	s1 = argv[2];
	s2 = argv[3];
	if (stt_read_file(argv[1], file_string) == -1)
		return (1);
	stt_replace(file_string, s1, s2);
	output.open(filename.c_str());
	if (output.is_open() == false)
	{
		std::cerr << "Failed saving file\n";
		return (1);
	}
	output << file_string;
	return (0);
}