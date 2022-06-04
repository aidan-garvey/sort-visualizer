
#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdint.h>

// Size of array that will be sorted. Ensure this value is
// less than the horizontal character width of your terminal.
// On a full-screen, 1920x1080 console, 240 is the limit.
// This value can always be overridden by providing a different
// number in the command line (ex: ./sort_all 100)
#define ARR_SIZE 240
// The vertical "squish" of the displayed array. For example,
// if SQUISH is 2, every 2 values will share the same height.
#define SQUISH 4
// Number of milliseconds to wait after printing the array.
#define WAIT_MILLIS 2
// The character used to display the array.
#define DISPLAY_CHAR "#"

// shuffle the array before sorting
void shuffle (int* array, int len);

// functions to display the array in the console
void chart (int* array, int len, int compares, int copies);
void chart_hilite (int* array, int len, int compares, int copies, int hilite);
void chart_2hilite (int* array, int len, int compares, int copies, int l_hilite, int r_hilite);
void merge_chart (int* arr_a, int* arr_b, int merge, int len, int compares, int copies);

// sorting algorithms, which call the chart functions as they sort
void merge_sort (int* array, int len);
void quicksort (int* array, int len);
void quickworst (int* array, int len);
void heap_sort (int* array, int len);
void cocktail_sort (int* array, int len);
void radix_sort (uint32_t* array, int len);

#endif

