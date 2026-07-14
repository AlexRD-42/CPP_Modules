#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <set>
#include <string>
#include <stdint.h>

struct RateEntry
{
	uint32_t	date;
	float		rate;

	bool operator<(const RateEntry& other) const;
};

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename) const;

private:
	std::set<RateEntry> _rates;

	static std::string trim(const std::string& text);
	static bool parseDate(const std::string& text, uint32_t& date);
	static bool parseNumber(const std::string& text, double& value);

	bool findRate(uint32_t date, float& rate) const;
	void processInputLine(const std::string& line) const;
};

#endif
