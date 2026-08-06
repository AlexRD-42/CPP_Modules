#include "Span.hpp"

// === Methods ================================================================
void Span::addNumber(int number)
{
	if (data.size() >= max_size)
		throw std::out_of_range("Out of range");

	data.push_back(number);
	isSorted = false;
}

void Span::addNumber(int number, unsigned int count)
{
	if (data.size() + count >= max_size)
		throw std::out_of_range("Out of range");

	data.insert(data.end(), count, number);
	isSorted = false;
}

static inline
bool s_span(std::vector<int> &data, bool isSorted)
{
	if (data.size() <= 1)
		throw std::runtime_error("Not enough numbers");

	if (isSorted == false)
	{
		isSorted = true;
		std::sort(data.begin(), data.end());
	}
	return (isSorted);
}

size_t Span::shortestSpan()
{
	size_t	min = SIZE_MAX;
	size_t	delta;

	isSorted = s_span(data, isSorted);
	const size_t length = data.size() - 1;
	for (size_t i = 0; i < length; i++)
	{
		delta = (size_t) data[i + 1] - (size_t) data[i];
		if (delta < min)
			min = delta;
	}
	return (min);
}

size_t Span::longestSpan()
{
	size_t	max = 0;
	size_t	delta;

	isSorted = s_span(data, isSorted);
	const size_t length = data.size() - 1;

	for (size_t i = 0; i < length; i++)
	{
		delta = (size_t) data[i + 1] - (size_t) data[i];
		if (delta > max)
			max = delta;
	}
	return (max);
}

// === Canonical Form and Constructors ========================================
Span::Span() :
	data(0),
	max_size(0),
	isSorted(false)
{
}

Span::Span(const Span &other) :
	data(other.data),
	max_size(other.max_size),
	isSorted(other.isSorted)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->data = other.data;
		this->max_size = other.max_size;
	}
	return (*this);
}