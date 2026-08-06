#pragma once

template <typename Type>
void swap(Type &x, Type &y)
{
	Type tmp = x;

	x = y;
	y = tmp;
}

template <typename Type>
const Type& min(const Type &x, const Type &y)
{
	return (x < y ? x : y);
}

template <typename Type>
const Type& max(const Type &x, const Type &y)
{
	return (x > y ? x : y);
}
