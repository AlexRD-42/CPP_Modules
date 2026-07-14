#include "core.h"

static
void s_merge(i32 *array, i32 *tmp, u32 low, u32 mid, u32 high)
{
	if (array[mid] <= array[mid + 1])
    	return;

	while (array[low] <= array[mid + 1])
		low++;

	i32 *array1 = array + low;
	i32 *array1_end = array + mid + 1;
	i32 *array2 = array + mid + 1;
	i32 *array2_end = array + high + 1;
	i32 *otmp = tmp;

	while (true)
	{
		if (*array1 <= *array2)
		{
			*tmp++ = *array1++;
			if (array1 >= array1_end)
			{
				while (array2 < array2_end)
					*tmp++ = *array2++;
				break;
			}
		}
		else
		{
			*tmp++ = *array2++;
			if (array2 >= array2_end)
			{
				while (array1 < array1_end)
					*tmp++ = *array1++;
				break;
			}
		}
	}
	MEMCPY_BUILTIN(array + low, otmp, (tmp - otmp) * sizeof(*tmp));
}

static
void s_merge_sort(i32 *array, i32 *tmp, u32 low, u32 high)
{
	if (low >= high)
		return;

	u32 mid = low + (high - low) / 2;
	s_merge_sort(array, tmp, low, mid);
    s_merge_sort(array, tmp, mid + 1, high);
    s_merge(array, tmp, low, mid, high);
}

void merge_sort(i32 *array, i32 *tmp, u32 length)
{
	s_merge_sort(array, tmp, 0, length - 1);
}
