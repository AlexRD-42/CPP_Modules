#pragma once

#include <cstddef>
#include <cstdint>
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
	void addNumber(int number, unsigned int count);
	size_t shortestSpan();
	size_t longestSpan();

private:
	bool				isSorted;
	std::vector<int>	data;
	size_t				max_size;	// I think this might be necessary because max_size might not be enforceable in a vector
};

