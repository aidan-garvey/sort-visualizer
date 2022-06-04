#include <limits.h>
#include <stdio.h>
#include "sort.h"

static int compares = 0;
static int copies = 0;

// pivot strategies
typedef enum
{
	MIDDLE, // choose the element in the middle of the current subarray
	WORST, // choose the worst-case (minimum) pivot
	BEST // choose the best-case (median) pivot
} pivot_mode;

static int best_pivot(array, lo, hi)
	int* array;
	int lo, hi;
{
	// TODO
	return array[(hi + lo) / 2];
}

// return the value of the worst-case pivot
static int worst_pivot(array, lo, hi)
	int* array;
	int lo, hi;
{
	int min = INT_MAX;
	for (int i = lo; i <= hi; i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

// Quicksort partition helper function. Full length given for calls to chart functions
static int partition(array, lo, hi, len, pivmode)
	int* array;
	int lo, hi;
	int len;
	pivot_mode pivmode;
{
	int pivot;
	if (pivmode == WORST)
	{
		pivot = worst_pivot(array, lo, hi);
	}
	else if (pivmode == BEST)
	{
		pivot = best_pivot(array, lo, hi);
	}
	else
	{
		pivot = array[(hi + lo) / 2];
	}
	int i = lo;
	int j = hi;
	while (1)
	{
		while (array[i] < pivot)
		{
			++i;
			++compares;
			if (i % 4 == 0)
				chart_2hilite(array, len, compares, copies, i, j);
		}
		while (array[j] > pivot)
		{
			--j;
			++compares;
			if (j % 4 == 0)
				chart_2hilite(array, len, compares, copies, i, j);
		}

		if (i >= j)
			return j;

		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		chart_2hilite(array, len, compares, ++copies, i, j);
	}
}

static void quicksort_(array, lo, hi, len, pivmode)
	int* array;
	int lo, hi;
	int len;
	pivot_mode pivmode;
{
	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		int pivot = partition(array, lo, hi, len, pivmode);
		quicksort_(array, lo, pivot, len, pivmode);
		quicksort_(array, pivot+1, hi, len, pivmode);
	}
}

// call quicksort with MIDDLE pivot selection
void quicksort(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;
	quicksort_(array, 0, len-1, len, MIDDLE);
}

// call quicksort with worst case pivot selection
void quickworst(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;
	quicksort_(array, 0, len-1, len, WORST);
}

// call quicksort with best case pivot selection
void quickbest(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;
	quicksort_(array, 0, len-1, len, BEST);
}

