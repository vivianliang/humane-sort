humane-sort
===========

Sorts a list of strings from file or stdin in human-readable way
instead of only by strict ASCII comparisons.

For example:

	a1.txt
	a2.txt
	...
	a9.txt
	a10.txt
	a11.txt

Rather than the generic ASCII sort which would result in:

	a1.txt
	a10.txt
	a11.txt
	a2.txt
	...
	a9.txt

## Compilation

To compile:

	make all

## Usage

Read list of strings from file, sort, and print sorted list to stdout.
Example:

	./humane_sort file.txt

Read list of strings from stdin, sort, and print sorted list to stdout.
Examples:

	./humane_sort < file.txt
	cat file.txt | ./humane_sort
	ls | ./humane_sort

Run development tests:

	./test

## Expected Humane Behavior:

As described above, digit substrings will be sorted by decimal value
rather than ASCII character.

	a1.txt
	a2.txt
	a9.txt
	a10.txt
	a12.txt
	
Leading zeroes will be treated in the expected ASCII-like fashion,
with priority given to the most leading zeroes.
When there are two numbers with the same number of zeroes,
they are evaluated by numerical value.

	00002.txt
	001.txt
	002.txt
	009.txt
	0010.txt
	0011.txt
	1.txt
	2.txt
	9.txt
	10.txt

Symbols will appear before alphanumeric characters.

	!!##
	@#&^!@
	00002.txt
	0002.txt

Case is ignored:

	a9.txt
	A10.txt
	a11.txt
	B1.txt
	b2.txt
	B3.txt