#include "RPN.hpp"

#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		std::cout << evaluate_rpn(argv[1]) << std::endl;
	}
	catch (const std::exception &exception)
	{
		(void)exception;
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
