#include "sort.h"

static int compares = 0;
static int copies = 0;

// Perform cocktail shaker sort, display the chart roughly every 4 swaps,
// highlight the element being sifted.
void cocktail_sort(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;

	int lo = 0;
	int hi = len - 2;
	int newLo, newHi;
	while (lo <= hi)
	{
		newLo = hi;
		newHi = lo;
		for (int i = lo; i <= hi; i++)
		{
			++compares;
			if (array[i] > array[i+1])
			{
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				newHi = i;
				++copies;
				if (i % 4 == 0)
					chart_hilite(array, len, compares, copies, i + 1);
			}
		}

		hi = newHi - 1;

		for (int i = hi; i >= lo; i--)
		{
			++compares;
			if (array[i] > array[i+1])
			{
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				newLo = i;
				++copies;
				
				if (i % 4 == 0)
					chart_hilite(array, len, compares, copies, i);
			}
		}

		lo = newLo + 1;
	}

	chart(array, len, compares, copies);
}

