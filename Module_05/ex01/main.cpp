#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

static void printSection(const char* title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	printSection("valid forms and output");
	Form standard("StandardForm", 50, 25);
	std::cout << standard << "\n";

	printSection("invalid form grades");
	try
	{
		Form invalidSignHigh("InvalidSignHigh", 0, 25);
		std::cout << invalidSignHigh << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Sign grade 0 rejected: " << e.what() << "\n";
	}
	try
	{
		Form invalidExecLow("InvalidExecLow", 25, 151);
		std::cout << invalidExecLow << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Execution grade 151 rejected: " << e.what() << "\n";
	}

	printSection("failed and successful signing");
	Bureaucrat junior("Junior", 100);
	Bureaucrat exact("ExactGrade", 50);
	junior.signForm(standard);
	std::cout << standard << "\n";
	exact.signForm(standard);
	std::cout << standard << "\n";

	printSection("copy construction preserves state");
	Form copy(standard);
	std::cout << copy << "\n";

	printSection("assignment copies mutable signed state");
	Form assigned("AssignedMetadataStaysConstant", 150, 150);
	std::cout << "Before assignment: " << assigned << "\n";
	assigned = standard;
	std::cout << "After assignment: " << assigned << "\n";

	printSection("bureaucrat grade boundaries");
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Invalid bureaucrat rejected: " << e.what() << "\n";
	}

	return 0;
}
