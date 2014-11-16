all: humane_sort test

humane_sort: humane_sort.o main.o
	gcc -o $@ $^ -I.

test: humane_sort.o humane_test.o
	gcc -o $@ $^ -I.
