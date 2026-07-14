#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static void printSection(const char* title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	std::srand(42);

	Bureaucrat chief("Chief", 1);
	Bureaucrat shrubExecutor("ShrubExecutor", 137);
	Bureaucrat weakExecutor("WeakExecutor", 140);
	Bureaucrat robotExecutor("RobotExecutor", 45);
	Bureaucrat weakRobotExecutor("WeakRobotExecutor", 46);

	ShrubberyCreationForm shrub("review_garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	printSection("initial form state");
	std::cout << shrub << "\n";
	std::cout << robot << "\n";
	std::cout << pardon << "\n";

	printSection("execution before signing");
	chief.executeForm(shrub);
	chief.executeForm(robot);
	chief.executeForm(pardon);

	printSection("signing attempts");
	weakExecutor.signForm(robot);
	chief.signForm(shrub);
	chief.signForm(robot);
	chief.signForm(pardon);

	printSection("execution grade checks");
	weakExecutor.executeForm(shrub);
	shrubExecutor.executeForm(shrub);
	weakRobotExecutor.executeForm(robot);
	robotExecutor.executeForm(robot);
	chief.executeForm(pardon);

	printSection("shrubbery file verification");
	std::ifstream file("review_garden_shrubbery");
	if (!file)
		std::cout << "Could not open generated shrubbery file\n";
	else
	{
		std::string firstLine;
		std::getline(file, firstLine);
		std::cout << "First line: " << firstLine << "\n";
	}

	printSection("robotomy repeated trials");
	for (int i = 0; i < 5; ++i)
		chief.executeForm(robot);

	printSection("copy and assignment preserve signed state");
	RobotomyRequestForm robotCopy(robot);
	RobotomyRequestForm robotAssigned("TemporaryTarget");
	robotAssigned = robot;
	std::cout << robotCopy << "\n";
	std::cout << robotAssigned << "\n";
	chief.executeForm(robotCopy);
	chief.executeForm(robotAssigned);

	return 0;
}
