
#include <stdio.h>
#include <unistd.h>
#include "sort.h"

#define COL_RED "\x1b[0;31m"
#define COL_BLUE "\x1b[1;34m"
#define COL_CYAN "\x1b[1;36m"
#define COL_YELLOW "\x1b[1;33m"
#define COL_NONE "\x1b[0m"
#define HIDE_CURSOR "\x1b[?25l"
#define SHOW_CURSOR "\x1b[?25h"

// Print a visualization of the array, return cursor to top left.
// Sorted elements are blue, unsorted are red.
// Up to two columns can be highlighted in yellow to better illustrate
// how the sort is working.
static void chart_ (array, len, compares, copies, l_hilite, r_hilite)
	int* array;
	int len, compares, copies, l_hilite, r_hilite;
{
	printf(HIDE_CURSOR);
	for (int height = len; height >= 0; height -= SQUISH)
	{
		for (int j = 0; j < len; j++)
		{
			if (j == l_hilite || j == r_hilite)
				printf(COL_YELLOW);
			else if (array[j] == j)
				printf(COL_BLUE);
			else
				printf(COL_RED);

			if (array[j] >= height)
				printf(DISPLAY_CHAR);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf(COL_CYAN "comparisons: %d, swaps: %d\r", compares, copies);
	printf(COL_NONE);
	// move cursor to top left
	printf("\x1b[%uA", len / SQUISH + 1);
	printf(SHOW_CURSOR);
	usleep(WAIT_MILLIS * 1000);
}

// display the chart with two columns highlighted
void chart_2hilite (array, len, compares, copies, l_hilite, r_hilite)
	int* array;
	int len, compares, copies, l_hilite, r_hilite;
{
	chart_(array, len, compares, copies, l_hilite, r_hilite);
}

// display the chart with one column highlighted
void chart_hilite (array, len, compares, copies, hilite)
	int* array;
	int len, compares, copies, hilite;
{
	chart_(array, len, compares, copies, hilite, -1);
}

// display the chart with no columns highlighted
void chart (array, len, compares, copies)
	int* array;
	int len, compares, copies;
{
	chart_(array, len, compares, copies, -1, -1);
}

// Special function for merge sort, displays the destination array to the left
// of merge_line and the source array to the right of merge_line.
void merge_chart (arr_a, arr_b, merge_line, len, compares, copies)
	int* arr_a;
	int* arr_b;
	int merge_line, len, compares, copies;
{
	printf(HIDE_CURSOR);
	for (int height = len; height >= 0; height -= SQUISH)
	{
		for (int j = 0; j < merge_line; j++)
		{
			if (arr_a[j] == j)
				printf(COL_BLUE);
			else
				printf(COL_RED);

			if (arr_a[j] >= height)
				printf(DISPLAY_CHAR);
			else
				printf(" ");
		}
		for (int j = merge_line; j < len; j++)
		{
			if (arr_b[j] == j)
				printf(COL_BLUE);
			else
				printf(COL_RED);

			if (arr_b[j] >= height)
				printf(DISPLAY_CHAR);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf(COL_CYAN "comparisons: %d, swaps: %d\r", compares, copies);
	printf(COL_NONE);
	// move cursor to top
	printf("\x1b[%uA", len / SQUISH + 1);
	printf(SHOW_CURSOR);
	usleep(WAIT_MILLIS * 1000);
}

