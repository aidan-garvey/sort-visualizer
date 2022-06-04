#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#ifdef SORT_ALL
#define SORT_MERGE
#define SORT_QUICK
#define SORT_HEAP
#define SORT_COCKTAIL
#define SORT_RADIX
#endif

int main(argc, argv)
	int argc;
	char* argv[];
{
	// attempt to get length from command line
	int length = ARR_SIZE;
	if (argc > 1)
	{
		int l = atoi(argv[1]);
		if (l > 0)
			length = l;
		else
		{
			printf("usage: %s [array_length]\n\tarray_length must be > 0\n", argv[0]);
		}
	}

	int* array = (int*) malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		array[i] = i;
	}
#ifdef SORT_MERGE
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("merge sort\n");
	merge_sort(array, length);
#endif
#ifdef SORT_QUICK
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("quicksort (arbitrary pivot)...\n");
	quicksort(array, length);
#endif
#ifdef SORT_QUICK_WORST
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("quicksort (worst-case pivot)...\n");
	quickworst(array, length);
#endif
#ifdef SORT_HEAP
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("heap sort...\n");
	heap_sort(array, length);
#endif
#ifdef SORT_COCKTAIL
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("cocktail shaker sort...\n");
	cocktail_sort(array, length);
#endif
#ifdef SORT_RADIX
	printf("shuffling...\n");
	shuffle(array, length);
	chart(array, length, 0, 0);
	printf("radix sort...\n");
	radix_sort((uint32_t*)array, length);
#endif

	free(array);
	return 0;
}
