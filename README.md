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

## Expected Humane Behavior

As described above, digit substrings will be sorted by decimal value
rather than ASCII character.

	a1.txt
	a2.txt
	a9.txt
	a10.txt
	a12.txt
	
Leading zeroes will be ignored.

	1.txt
	002.txt

When two number values are equal, leading zeroes will have priority.

	00002.txt
	0002.txt
	002.txt

Symbols will appear before alphanumeric characters, and numbers will appear
before alphabetic characters.

	!!##
	@#&^!@
	00002.txt
	0002.txt
	abc.txt

Case is ignored:

	a9.txt
	A10.txt
	a11.txt
	B1.txt
	b2.txt
	B3.txt

### Constraints

* Maximum line length:	 100 (Adjustable in main.c)
* Maximum number of lines: 300 (Adjustable in main.c)
* Integer substrings within string lines cannot exceed 18446744073709551615 (26^4-1)