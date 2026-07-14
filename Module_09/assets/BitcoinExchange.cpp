#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

bool RateEntry::operator<(const RateEntry& other) const
{
	return date < other.date;
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

std::string BitcoinExchange::trim(const std::string& text)
{
	std::string::size_type first = 0;
	std::string::size_type last = text.size();

	while (first < last
		&& std::isspace(static_cast<unsigned char>(text[first])))
		++first;
	while (last > first
		&& std::isspace(static_cast<unsigned char>(text[last - 1])))
		--last;
	return text.substr(first, last - first);
}

static
uint32_t	s_string_to_timestamp(const char **str_ptr)
{
	long year, month, day;
	static char days_in_month[12] =	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const char *ptr = *str_ptr;
	char *end_ptr;

	year = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == ptr || year < 2009 || year >= 9000 || *end_ptr != '-')
		return 0;
	ptr = end_ptr + 1;

	month = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == ptr || month <= 0 || month > 12 || *end_ptr != '-')
		return 0;
	ptr = end_ptr + 1;

	day = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == ptr)
		return 0;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))	// Leap year checking
		days_in_month[1] = 29;
	if (day <= 0 || day > days_in_month[month - 1])
		return 0;

	*str_ptr = end_ptr;
	return (year * 10000 + month * 100 + day);
}

bool BitcoinExchange::parseDate(const std::string& text, uint32_t& date)
{
	const char	*ptr = text.c_str();
	uint32_t	timestamp = s_string_to_timestamp(&ptr);

	if (timestamp == 0 || *ptr != '\0')
		return false;
	date = timestamp;
	return true;
}

bool BitcoinExchange::parseNumber(const std::string& text, double& value)
{
	char trailing;
	std::istringstream stream(text);

	if (text.empty())
		return false;
	stream >> value;
	if (stream.fail())
		return false;
	if (stream >> trailing)
		return false;
	return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	_rates.clear();
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");
	while (std::getline(file, line))
	{
		std::string::size_type comma;
		std::string dateText;
		std::string rateText;
		RateEntry entry;
		double parsedRate;

		line = trim(line);
		if (line.empty())
			continue;
		comma = line.find(',');
		if (comma == std::string::npos
			|| line.find(',', comma + 1) != std::string::npos)
			throw std::runtime_error("Error: bad database entry.");
		dateText = trim(line.substr(0, comma));
		rateText = trim(line.substr(comma + 1));
		if (!parseDate(dateText, entry.date)
			|| !parseNumber(rateText, parsedRate) || parsedRate < 0.0)
			throw std::runtime_error("Error: bad database entry.");
		entry.rate = static_cast<float>(parsedRate);
		_rates.insert(entry);
	}
	if (_rates.empty())
		throw std::runtime_error("Error: empty database.");
}

bool BitcoinExchange::findRate(uint32_t date, float& rate) const
{
	RateEntry key;
	std::set<RateEntry>::const_iterator it;

	key.date = date;
	key.rate = 0.0f;
	it = _rates.lower_bound(key);
	if (it != _rates.end() && it->date == date)
	{
		rate = it->rate;
		return true;
	}
	if (it == _rates.begin())
		return false;
	--it;
	rate = it->rate;
	return true;
}

void BitcoinExchange::processInputLine(const std::string& line) const
{
	std::string::size_type separator = line.find('|');
	std::string dateText;
	std::string valueText;
	uint32_t date;
	double value;
	float rate;

	if (separator == std::string::npos
		|| line.find('|', separator + 1) != std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	dateText = trim(line.substr(0, separator));
	valueText = trim(line.substr(separator + 1));
	if (!parseDate(dateText, date) || !parseNumber(valueText, value))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	if (value < 0.0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	if (!findRate(date, rate))
	{
		std::cout << "Error: no exchange rate available for "
			<< dateText << '.' << std::endl;
		return;
	}
	std::cout << dateText << " => " << value << " = "
		<< value * rate << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	std::string line;
	bool firstLine = true;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line))
	{
		if (firstLine && trim(line) == "date | value")
		{
			firstLine = false;
			continue;
		}
		firstLine = false;
		if (!trim(line).empty())
			processInputLine(line);
	}
}
