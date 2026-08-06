#pragma once

#include <cstddef>
#include <iterator>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
public: // Canonical Form and Constructors
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span &other);
	Span& operator=(const Span &other);
	void addNumber(int number);
	void addNumber(int number, int count);
	void addNumber(int number, unsigned int count);
	template <typename Iterator>
	void addNumber(Iterator first, Iterator last);
	size_t shortestSpan();
	size_t longestSpan();

private:
	bool				isSorted;
	std::vector<int>	data;
	size_t				max_size;	// I think this might be necessary because max_size might not be enforceable in a vector
};

template <typename Iterator>
void Span::addNumber(Iterator first, Iterator last)
{
	size_t count = static_cast<size_t>(std::distance(first, last));

	if (count > max_size - data.size())
		throw std::out_of_range("Out of range");
	data.insert(data.end(), first, last);
	isSorted = false;
}
