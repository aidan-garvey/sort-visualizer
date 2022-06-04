#include <stdlib.h>
#include "sort.h"

#define SWAP_MULT 3

// Perform (len * SWAP_MULT) random swaps of elements
void shuffle(array, len)
	int* array;
	int len;
{
	int index1, index2, temp;
	for (int i = 0; i < len * SWAP_MULT; i++)
	{
		index1 = rand() % len;
		index2 = rand() % len;
		temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
		if (i % 4 == 0)
			chart(array, len, 0, i);
	}
}

