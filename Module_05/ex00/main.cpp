#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

static void printSection(const char* title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	printSection("valid construction and stream output");
	try
	{
		Bureaucrat highest("Highest", 1);
		Bureaucrat lowest("Lowest", 150);
		std::cout << highest << "\n";
		std::cout << lowest << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << "\n";
	}

	printSection("invalid construction");
	try
	{
		Bureaucrat invalidHigh("InvalidHigh", 0);
		std::cout << invalidHigh << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Grade 0 rejected: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat invalidLow("InvalidLow", 151);
		std::cout << invalidLow << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Grade 151 rejected: " << e.what() << "\n";
	}

	printSection("increment and decrement");
	Bureaucrat middle("Middle", 75);
	std::cout << middle << "\n";
	middle.incrementGrade();
	std::cout << "After increment: " << middle << "\n";
	middle.decrementGrade();
	std::cout << "After decrement: " << middle << "\n";

	printSection("boundary exceptions preserve state");
	Bureaucrat top("Top", 1);
	try
	{
		top.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Cannot increment grade 1: " << e.what() << "\n";
	}
	std::cout << top << "\n";

	Bureaucrat bottom("Bottom", 150);
	try
	{
		bottom.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Cannot decrement grade 150: " << e.what() << "\n";
	}
	std::cout << bottom << "\n";

	printSection("copy construction and assignment");
	Bureaucrat original("Original", 42);
	Bureaucrat copy(original);
	Bureaucrat assigned("AssignedNameStaysConstant", 100);
	assigned = original;
	std::cout << "Original: " << original << "\n";
	std::cout << "Copy: " << copy << "\n";
	std::cout << "Assigned: " << assigned << "\n";

	return 0;
}
