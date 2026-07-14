#include "core.h"
#include <vector>

typedef struct
{
	u32 pair_index;
	i32	value;
}	pair_t;

typedef struct
{
	u32 	prev_index;
	pair_t	entry;
}	node_t;

void fj_binary_split(std::vector<i32> &input, std::vector<node_t> &winner, std::vector<pair_t> &loser)
{
	size_t i = 0;
	size_t k = 0;

	for (i = 0; i < input.size() / 2; i++)
	{
		if (input[k] > input[k + 1])
		{
			winner[i].entry.value = input[k++];
			loser[i].value = input[k++];
		}
		else
		{
			loser[i].value = input[k++];
			winner[i].entry.value = input[k++];
		}
		winner[i].entry.pair_index = i;
		loser[i].pair_index = i;
	}
	if (input.size() % 2 != 0)
	{
		loser[i].pair_index = i;
		loser[i].value = input[k];
	}
}

void fj_binary_split(std::vector<node_t> &input, std::vector<node_t> &winner, std::vector<pair_t> &loser)
{
	size_t i = 0;
	size_t k = 0;

	for (i = 0; i < input.size() / 2; i++)
	{
		if (input[k].value > input[k + 1].value)
		{
			winner[i].prev_index = input[k].curr_index;
			winner[i].entry.value = input[k++].value;
			loser[i].value = input[k++].value;
		}
		else
		{
			loser[i].value = input[k++].value;
			winner[i].prev_index = input[k].curr_index;
			winner[i].entry.value = input[k++].value;
		}
		winner[i].entry.pair_index = i;
		loser[i].pair_index = i;
	}
	if (input.size() % 2 != 0)
	{
		loser[i].pair_index = i;
		loser[i].value = input[k].entry.value;
	}
}

// Uses the saved index as a better starting point to reduce comparisons
// Normally median would be (upper + lower) / 2
static
void fj_insert(std::vector<pair_t> &winner, i32 value, size_t insertion_index)
{
	size_t lower = 0, upper = winner.size(), median = insertion_index;

	while (lower < upper)
	{
		if (value > winner[median].value)
		{
			if (value < winner[median - 1].value)
				break;
			lower = median;
		}
		else
		{
			if (value > winner[median - 1].value)
				break;
			upper = median;
		}
		median = (upper + lower) / 2;
	}
	// Insert here
}

// J(n - 1) + 2 × J(n - 2)
// 0, 2, 4, 10, 20, 42, 84, 170
// 1, 3, 5, 11, 21, 43, 85, 171,
void fj_merge(std::vector<pair_t> &winner, std::vector<pair_t> &loser)
{
	const size_t insert_count = loser.size();
	size_t	previous = 1;
	size_t	current = 0;
	size_t	next = 1;

	while (true)
	{
		for (size_t i = MIN(next, insert_count); i > current; i--)
			fj_insert(winner, loser[winner[i - 1].curr_index], i);

		if (next >= insert_count)
			break;
		previous = current;
		current = next;
		next = current + 2 * previous;
	}
}

// index 0 is effectively base
// index 1 is out
static
void s_sort(std::vector<pair_t> &array)
{
	const size_t vec_size = (array.size() + 1) / 2;
	std::vector<pair_t> winners(vec_size);
	std::vector<i32> losers(vec_size);

	fj_binary_split(array, winners, losers);
	if (winners.size() > 1)
		s_sort(winners);
	fj_merge(winners, losers);

	const size_t length = winners.size();
	for (size_t i = 0; i < length; i++)
		winners[i].curr_index = winners[i].prev_index;	// Restores previous index

	array = winners;
}

void fj_sort(std::vector<i32> &array)
{
	std::vector<pair_t> winners(array.size());
	std::vector<i32> losers((array.size() + 1) / 2);

	fj_binary_split(array, winners, losers);
	s_sort(winners);
	fj_merge(winners, losers);

	const size_t length = array.size();
	for (size_t i = 0; i < length; i++)
		array[i] = winners[i].value;
}

// Input: 1 20 4 40 7 50 3 10
// (1, 20) (4, 40) (7 50) (3 10)
// A: 20 (&1), 40 (&4), 50 (&7), 10 (&3)
// B: 1, 4, 7, 3
