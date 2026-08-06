#include "Span.hpp"
#include <climits>
#include <iostream>
#include <vector>

int main()
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> numbers;
	for (int i = 0; i < 10000; i++)
		numbers.push_back(i * 2);
	Span large(10000);
	large.addNumber(numbers.begin(), numbers.end());
	std::cout << "10,000-number shortest span: " << large.shortestSpan() << std::endl;
	std::cout << "10,000-number longest span: " << large.longestSpan() << std::endl;

	Span limits(2);
	limits.addNumber(INT_MIN);
	limits.addNumber(INT_MAX);
	std::cout << "Integer-limit span: " << limits.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Full span: " << e.what() << std::endl;
	}

	try
	{
		Span empty(1);
		empty.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Empty span: " << e.what() << std::endl;
	}
	return (0);
}
