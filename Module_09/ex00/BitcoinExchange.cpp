#include "BitcoinExchange.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

bool RateEntry::operator<(const RateEntry& other) const
{
	return date < other.date;
}

static std::string	trim(const std::string& text)
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

static uint32_t	string_to_timestamp(const char **str_ptr)
{
	long			year;
	long			month;
	long			day;
	int			days_in_month[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	const char	*ptr = *str_ptr;
	const char	*start;
	char			*end_ptr;

	start = ptr;
	year = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == start || end_ptr - start != 4 || *end_ptr != '-')
		return 0;
	if (year < 2009 || year >= 9000)
		return 0;
	ptr = end_ptr + 1;

	start = ptr;
	month = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == start || end_ptr - start != 2 || *end_ptr != '-')
		return 0;
	if (month <= 0 || month > 12)
		return 0;
	ptr = end_ptr + 1;

	start = ptr;
	day = std::strtol(ptr, &end_ptr, 10);
	if (end_ptr == start || end_ptr - start != 2)
		return 0;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		days_in_month[1] = 29;
	if (day <= 0 || day > days_in_month[month - 1])
		return 0;

	*str_ptr = end_ptr;
	return static_cast<uint32_t>(year * 10000 + month * 100 + day);
}

static bool	parse_date(const std::string& text, uint32_t& date)
{
	const char *ptr = text.c_str();

	date = string_to_timestamp(&ptr);
	return date != 0 && *ptr == '\0';
}

static bool	parse_number(const std::string& text, double& value)
{
	char	*end_ptr;

	if (text.empty())
		return false;
	errno = 0;
	value = std::strtod(text.c_str(), &end_ptr);
	if (end_ptr == text.c_str() || *end_ptr != '\0' || errno == ERANGE)
		return false;
	return true;
}

void	load_database(const std::string& filename, std::set<RateEntry>& rates)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	rates.clear();
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");
	while (std::getline(file, line))
	{
		std::string::size_type comma;
		std::string date_text;
		std::string rate_text;
		RateEntry entry;
		double parsed_rate;

		line = trim(line);
		if (line.empty())
			continue;
		comma = line.find(',');
		if (comma == std::string::npos
			|| line.find(',', comma + 1) != std::string::npos)
			throw std::runtime_error("Error: bad database entry.");
		date_text = trim(line.substr(0, comma));
		rate_text = trim(line.substr(comma + 1));
		if (!parse_date(date_text, entry.date)
			|| !parse_number(rate_text, parsed_rate) || parsed_rate < 0.0)
			throw std::runtime_error("Error: bad database entry.");
		entry.rate = static_cast<float>(parsed_rate);
		rates.insert(entry);
	}
	if (rates.empty())
		throw std::runtime_error("Error: empty database.");
}

static
bool	find_rate(const std::set<RateEntry>& rates, uint32_t date, float& rate)
{
	RateEntry key;
	std::set<RateEntry>::const_iterator it;

	key.date = date;
	key.rate = 0.0f;
	it = rates.lower_bound(key);
	if (it != rates.end() && it->date == date)
	{
		rate = it->rate;
		return true;
	}
	if (it == rates.begin())
		return false;
	--it;
	rate = it->rate;
	return true;
}

static
void	process_input_line(const std::string& line,const std::set<RateEntry>& rates)
{
	std::string::size_type separator = line.find('|');
	std::string date_text;
	std::string value_text;
	uint32_t date;
	double value;
	float rate;

	if (separator == std::string::npos
		|| line.find('|', separator + 1) != std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	date_text = trim(line.substr(0, separator));
	value_text = trim(line.substr(separator + 1));
	if (!parse_date(date_text, date) || !parse_number(value_text, value))
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
	if (!find_rate(rates, date, rate))
	{
		std::cout << "Error: no exchange rate available for "
			<< date_text << '.' << std::endl;
		return;
	}
	std::cout << date_text << " => " << value << " = "
		<< value * rate << std::endl;
}

void	process_input_file(const std::string& filename, const std::set<RateEntry>& rates)
{
	std::ifstream file(filename.c_str());
	std::string line;
	bool first_line = true;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (std::getline(file, line))
	{
		if (first_line && trim(line) == "date | value")
		{
			first_line = false;
			continue;
		}
		first_line = false;
		if (!trim(line).empty())
			process_input_line(line, rates);
	}
}
