humane-sort
===========

a more humane sort

Sorts string characters according to ASCII value unless
two digit substrings are in question, in which case
the numbers will be evaluated numerically.

	a1.txt
	a2.txt
	a9.txt
	a10.txt
	a12.txt

This implementation will place all Uppercase letters
before Lowercase letters.

	A1.txt
	B1.txt
	C1.txt
	a1.txt
	b1.txt
	c1.txt

This implementation will place all smaller numerical
values before larger numerical values, regardless of
leading zeroes.

	1.txt
	002.txt

In the case that the numerical values are equal,
leading zeroes will have priority.

	001.txt
	1.txt
