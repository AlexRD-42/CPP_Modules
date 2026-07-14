#include "core.h"

static
void s_merge(i32 *tmp, i32 *low, i32 *mid, i32 *high)
{
	if (mid[0] <= mid[1])
    	return;

	while (*low <= mid[1])
		low++;

	i32 *left = low;
	i32 *right = mid + 1;
	i32 *out = tmp;

	while (true)
	{
		if (*left <= *right)
		{
			*out++ = *left++;
			if (left > mid)
			{
				while (right <= high)
					*out++ = *right++;
				break;
			}
		}
		else
		{
			*out++ = *right++;
			if (right > high)
			{
				while (left <= mid)
					*out++ = *left++;
				break;
			}
		}
	}
	const size_t delta = (size_t)(out - tmp);
	MEMCPY_BUILTIN(low, out, delta * sizeof(*tmp));
}

static
void s_merge_sort(i32 *tmp, i32 *low, i32 *high)
{
	if (low >= high)
		return;

	i32 *mid = low + (high - low) / 2;

	s_merge_sort(tmp, low, mid);
    s_merge_sort(tmp, mid + 1, high);
    s_merge(tmp, low, mid, high);
}

void merge_sort(i32 *array, i32 *tmp, u32 length)
{
	s_merge_sort(tmp, array, array + length - 1);
}
