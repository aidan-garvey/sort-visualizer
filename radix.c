#include "sort.h"

static int compares = 0;
static int copies = 0;

// Performs an in-place radix sort on the array, highlighting the boundaries
// of the current ones bucket and zeroes bucket.
static void radix (array, lo, hi, len, mask)
	uint32_t* array;
	int lo, hi, len;
	uint32_t mask;
{
	int zeroes = lo, ones = hi;
	while (zeroes < ones)
	{
		++compares;
		if ((array[zeroes] & mask) != 0)
		{
			int temp = array[zeroes];
			array[zeroes] = array[ones];
			array[ones] = temp;
			--ones;

			chart_2hilite((int*)array, len, compares, ++copies, zeroes, ones);
		}
		else
		{
			++zeroes;
		}

		if (zeroes % 4 == 0)
			chart_2hilite((int*)array, len, compares, copies, zeroes, ones);
	}

	// zeroes and ones are equal, correct them to point to the boundaries
	if ((array[zeroes] & mask) != 0)
		--zeroes;
	else
		++ones;

	if (mask > 1)
	{
		radix(array, lo, zeroes, len, mask>>1);
		radix(array, ones, hi, len, mask>>1);
	}
}

// find the MSB set in any number in the array,
// return a number with only that bit set
static uint32_t radix_mask (array, len)
	uint32_t* array;
	int len;
{
	uint32_t allbits = 0;
	for (int i = 0; i < len; i++)
		allbits |= array[i];
	const uint32_t masks[] = {0x2, 0xC, 0xF0, 0xFF00, 0xFFFF0000};
	const uint32_t powers[] = {1, 2, 4, 8, 16};
	uint32_t log_2 = 0;

	for (int i = 4; i >= 0; i--)
	{
		if (allbits & masks[i])
		{
			allbits >>= powers[i];
			log_2 |= powers[i];
		}
	}

	return 1 << log_2;
}

// find the best starting mask for MSB radix sort, call radix sort algorithm
void radix_sort (array, len)
	uint32_t* array;
	int len;
{
	compares = 0;
	copies = 0;
	uint32_t mask = radix_mask (array, len);
	radix (array, 0, len-1, len, mask);
	chart((int*)array, len, compares, copies);
}

