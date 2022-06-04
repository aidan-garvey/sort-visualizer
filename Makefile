
CFLAGS = -std=gnu11 -Wall -Wextra

%.o: %.c sort.h
	gcc $(CFLAGS) -c -o $@ $<

sort: sort.c shuffle.o chart.o merge.o quick.o heap.o cocktail.o radix.o sort.h
	gcc $(CFLAGS) -D SORT_ALL -o sort_all $^
	gcc $(CFLAGS) -D SORT_QUICK -o sort_quick $^
	gcc $(CFLAGS) -D SORT_MERGE -o sort_merge $^
	gcc $(CFLAGS) -D SORT_QUICK_WORST -o sort_qworst $^
	gcc $(CFLAGS) -D SORT_HEAP -o sort_heap $^
	gcc $(CFLAGS) -D SORT_COCKTAIL -o sort_cocktail $^
	gcc $(CFLAGS) -D SORT_RADIX -o sort_radix $^
	rm *.o
