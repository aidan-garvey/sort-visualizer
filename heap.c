
#include "sort.h"

static int compares = 0;
static int copies = 0;

// 0 -> 1, 2
// 1 -> 3, 4; 2 -> 5, 6
// 3 -> 7, 8; 4 -> 9, 10; 5 -> 11, 12; 6 -> 13, 14;
static int get_parent(index)
	int index;
{
	return (index - 1) / 2;
}

static int get_lchild(index)
	int index;
{
	return index * 2 + 1;
}

static void sift_down(array, lo, hi, len)
	int* array;
	int lo, hi, len;
{
	int root = lo;
	int child = get_lchild(root);
	while (child <= hi)
	{
		int swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= hi && array[swap] < array[child + 1])
			swap = child + 1;
		
		compares += 2;
		
		if (swap == root)
			return;

		int temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		chart(array, len, compares, ++copies);

		root = swap;
		child = get_lchild(root);
	}
}

static void heapify(array, len)
	int* array;
	int len;
{
	int start = get_parent(len - 1);
	while (start >= 0)
	{
		sift_down(array, start, len - 1, len);
		--start;
	}
}

// Perform a heap sort, print the list whenever an element is sorted
void heap_sort(array, len)
	int* array;
	int len;
{
	compares = 0;
	copies = 0;

	heapify(array, len);

	int last = len - 1;
	while (last > 0)
	{
		int temp = array[last];
		array[last] = array[0];
		array[0] = temp;
		++copies;
		chart(array, len, compares, copies);
		sift_down(array, 0, --last, len);
	}
	chart(array, len, compares, copies);
}

