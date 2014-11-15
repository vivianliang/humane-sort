#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "humane_sort.h"

/*
 * This function is intended to be used with qsort(). See IMPORTANT NOTE below.
 * 
 * Function humane_strcmp() works the same way as strcmp() in the C standard
 * library except that multi-digit substrings are treated as numerical
 * quantities rather than individual ASCII characters.
 *     For example, unlike in strcmp(), humane_strcmp() tells us
 *     a9.txt < a10.txt.
 *
 * Parameters:  a and b are *pointers to* the C strings we want to compare.
 *
 *              IMPORTANT NOTE:
 *
 * 				The prototype for this function is very misleading.
 *              It shows that it takes two (const void *) types, presumably
 *              the two C strings (const char *) we want to compare, but this
 *              is unfortunately, incorrect. To work as intended, this function
 *              must take a pointer to the C string.
 *              This is a helper function intended to be passed to
 *              qsort() for sorting an array of strings, so our parameters are
 *              actually of type (const char **). It is best if this function
 *              is only used as a parameter to qsort() to avoid confusion.
 * 
 * Return value: -1 : the first char or number that doesn't match has a lower
 *                    value in str1 than in str2
 *                0 : the contents of both strings are equal
 *                1 : the first char or number that doesn't match has a greater
 *                    value in str1 than in str2 
 */
int humane_strcmp(const void *a, const void *b){
	// NOTE: Because we need to pass this function to qsort(),
	//       this function must take a (const char **).
	const char* str1 = *(const char **)a;
	const char* str2 = *(const char **)b;
	int i = 0;
	unsigned long long num1;
	unsigned long long num2;
	int num_chars_in_num1;
	int num_chars_in_num2;
	char *next_char1;
	char *next_char2;

	// Make sure strings are of length 1 or more? what if we get a NULL?
	while (1){
		//printf("*str1: %c *str2: %c\n", *str1, *str2);
		//printf("%c %c\n", *str1, *str2);
		if (*str1 == *str2 && (!isdigit(*str1))){
			if (*str1 == '\0'){	// The strings are equal
				return 0;
			} else {
				str1++;
				str2++;
			}
		} else{
			if (*str1 == '\0') return -1;
			if (*str2 == '\0') return 1;
			if (isdigit(*str1) && isdigit(*str2)){
				num1 = strtoull (str1, &next_char1, 10);
				num2 = strtoull (str2, &next_char2, 10);
				if (num1 < num2){
					return -1;
				} else if (num1 > num2){
					return 1;
				// The two numbers are equal, but may have leading zeroes
				} else{
					// We handle leading zeros for two equal numbers only.
					// That is, 002 > 1 because it evaluates to 2 > 1.
					// If we have 001 and 1, 001 will come first.
					num_chars_in_num1 = next_char1 - str1;
					num_chars_in_num2 = next_char2 - str2;
					// str1 has more leading zeroes
					if (num_chars_in_num1 > num_chars_in_num2){
						return -1;
					// str2 has more leading zeroes
					} else if(num_chars_in_num2 > num_chars_in_num1){
						return 1;

					// The two numbers are completely equal (no leading zeroes)
					// Continue traversing the string.
					} else {
						str1 = next_char1;
						str2 = next_char2;
					}
				}
			// Compare ascii values for non-digits
			} else {
				if (*str1 < *str2){
					return -1;
				} else if(*str1 > *str2){
					return 1;
				} else {
					return 0; // We should never get here
				}
			}
		}
	}
	// We should never get here
}

void humane_sort(const char** str_list, unsigned long long num_elements){
	qsort(str_list,num_elements, sizeof(str_list[0]), humane_strcmp);
}

void print_sorted_strings(const char** str_list, unsigned long long num_elements){
	int i;
	for (i = 0;i <num_elements;i++){
		printf("%s\n", str_list[i]);
	}
}
