#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

static void printSection(const char* title)
{
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	std::srand(42);
	Intern intern;
	Intern copiedIntern(intern);
	Intern assignedIntern;
	assignedIntern = copiedIntern;

	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	const std::string targets[3] = {
		"intern_garden",
		"Bender",
		"Ford Prefect"
	};
	AForm* forms[3] = {0, 0, 0};

	printSection("known form dispatch");
	for (int i = 0; i < 3; ++i)
	{
		forms[i] = intern.makeForm(names[i], targets[i]);
		if (forms[i] != 0)
			std::cout << *forms[i] << "\n";
	}

	printSection("unknown form dispatch");
	AForm* unknown = intern.makeForm("tax evasion request", "Nobody");
	if (unknown == 0)
		std::cout << "Unknown form correctly returned a null pointer\n";
	delete unknown;

	Bureaucrat chief("Chief", 1);
	Bureaucrat junior("Junior", 150);

	printSection("unsigned execution and low-grade signing");
	if (forms[0] != 0)
	{
		chief.executeForm(*forms[0]);
		junior.signForm(*forms[0]);
	}

	printSection("sign and execute all intern-created forms");
	for (int i = 0; i < 3; ++i)
	{
		if (forms[i] != 0)
		{
			chief.signForm(*forms[i]);
			chief.executeForm(*forms[i]);
		}
	}

	printSection("cleanup");
	for (int i = 0; i < 3; ++i)
	{
		delete forms[i];
		forms[i] = 0;
	}
	std::cout << "All dynamically allocated forms deleted\n";

	return 0;
}
