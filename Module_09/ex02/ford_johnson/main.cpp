#include "core.h"
#include "merge_sort.hpp"
#include <iostream>
#define ARRAY_LENGTH 7

int main(int argc, char **argv)
{
	i32 array[ARRAY_LENGTH] = {38, 27, 43, 3, 9, 82, 10};
	i32 buffer[ARRAY_LENGTH];

	merge_sort(array, buffer, ARRAY_LENGTH);

	for (u32 i = 0; i < ARRAY_LENGTH; i++)
		std::cout << array[i] << ", ";
}
