#include "Span.hpp"
#include <limits>

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
	if (count > max_size - data.size())
		throw std::out_of_range("Out of range");

	data.insert(data.end(), count, number);
	isSorted = false;
}

void Span::addNumber(int number, int count)
{
	if (count < 0)
		throw std::out_of_range("Out of range");
	addNumber(number, static_cast<unsigned int>(count));
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
	size_t	min = std::numeric_limits<size_t>::max();
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
	isSorted = s_span(data, isSorted);
	return (static_cast<size_t>(data.back()) - static_cast<size_t>(data.front()));
}

// === Canonical Form and Constructors ========================================
Span::Span() :
	isSorted(false),
	data(0),
	max_size(0)
{
}

Span::Span(unsigned int N) :
	isSorted(false),
	data(0),
	max_size(N)
{
}

Span::Span(const Span &other) :
	isSorted(other.isSorted),
	data(other.data),
	max_size(other.max_size)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->isSorted = other.isSorted;
		this->data = other.data;
		this->max_size = other.max_size;
	}
	return (*this);
}
