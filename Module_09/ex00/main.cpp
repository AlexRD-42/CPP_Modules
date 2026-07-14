#include "BitcoinExchange.hpp"

#include <exception>
#include <iostream>
#include <set>

int main(int argc, char **argv)
{
	std::set<RateEntry> rates;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		load_database("data.csv", rates);
		process_input_file(argv[1], rates);
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}
