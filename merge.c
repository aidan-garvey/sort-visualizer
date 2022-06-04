
#include <stdlib.h>
#include "sort.h"

static int compares = 0;
static int copies = 0;

// merge two subarrays, print the arrays roughly every three copies
static void merge(src, dest, start, mid, end, len)
	int* src;
	int* dest;
	int start, mid, end;
	int len;
{
	int i = start;
	int j = mid;

	for (int k = start; k < end; k++)
	{
		if (i < mid && (j >= end || src[i] <= src[j]))
		{
			dest[k] = src[i];
			++i;
		}
		else
		{
			dest[k] = src[j];
			++j;
		}
		++compares;
		++copies;
		if (k % 3 == 0)
			merge_chart(dest, src, k+1, len, compares, copies);
	}
}

static void split_merge(src, dest, start, end, len)
	int* src;
	int* dest;
	int start, end;
	int len;
{
	if (end - start <= 1)
		return;
	int mid = (start + end) / 2;
	split_merge(dest, src, start, mid, len);
	split_merge(dest, src, mid, end, len);
	merge(src, dest, start, mid, end, len);
}

// Perform a merge sort
void merge_sort(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;
	int* scratch = (int*) malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
	{
		scratch[i] = array[i];
		++copies;
		if (i % 4 == 0)
			chart(array, len, compares, copies);
	}
	split_merge(scratch, array, 0, len, len);
	chart(array, len, compares, copies);

	free(scratch);
}

