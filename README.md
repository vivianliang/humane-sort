humane-sort
===========

a more humane sort

Sorts a list of strings from file or stdin according to ASCII value unless
digit substrings are in question, in which case the numbers will be evaluated
numerically.

	a1.txt
	a2.txt
	a9.txt
	a10.txt
	a12.txt

To compile:

	make all

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

---
Some implementation notes/expected behavior:
	
Leading zeroes will be treated in the expected ASCII-like fashion,
with priority given to the most leading zeroes.
When there are two numbers with the same number of zeroes,
they are evaluated by numerical value.

	00002.txt
	001.txt
	002.txt
	0010.txt
	1.txt
	2.txt
	9.txt
	10.txt

This implementation will place all Uppercase letters
before Lowercase letters. (Like the original ASCII sort.)

	A1.txt
	B1.txt
	C1.txt
	a1.txt
	b1.txt
	c1.txt

Symbols are evaluated by ASCII value, so they may
appear in between numbers and alphabets. This seems pretty
unintuitive, so this is a good thing to change in the future.

	!!##
	00002.txt
	0002.txt
	10.txt
	@#&^!@
	A10