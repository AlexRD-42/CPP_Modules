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

void	load_database(const std::string& filename,
			std::set<RateEntry>& rates);
void	process_input_file(const std::string& filename,
			const std::set<RateEntry>& rates);

#endif
