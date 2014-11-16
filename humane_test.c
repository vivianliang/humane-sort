#include <stdio.h>
#include <string.h>
#include "humane_sort.h"

#define NUM_STRCMP_TESTS 21
#define NUM_SORT_TESTS 1

typedef void (*test_ptr_t)(void);

/*
 * Tests for humane_strcmp():
 *      --------------------------
 *      Regular ASCII comparisons
 *      --------------------------
 * 		test0: @@#@ < abc
 *      test1: $#@* < 123
 *      test2: 123 < abc
 *      test3: ABC < []
 *      test4: [] < abc
 *      test5: ab** < ab12
 *      test6: a10 < b10         
 *      test7: B10 < a10         Upper case letters are handled as ASCII
 *      test8: a1.txt < a1txt
 *      --------------------------
 *      Humane number comparisons
 *      --------------------------
 *      test9: 2  < 100
 *      test10: a1.txt < a10.txt
 *      test11: a9.txt < a10.txt
 *      test12: a9abcd < a10

 *      test13: 0001 < 1      	If two number values are the same,
 *								leading zeroes will have priority.
 *
 *      test14: &1 < &001     	Same case as test13
 *
 *      test15: 001 < 2       	Another special case. When numbers evaluate
 *             					to different values, leading zeroes are ignored.
 *      test16: 001ab < 2ab   

 *      test17: abc123 = abc123
 *      test18: abc2 > abc001 
 *
 *      test19: ab1 < abc1
 *
 *      test20: ab1 > ab&1      ASCII comparison will put ab1 > ab&1
 *                              Code has not been implemented to handle
 * 								this differently.
 *      
 */

void test0(){
	const char* str[] = {"@@#@", "abc"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test1(){
	const char* str[] = {"$#@*", "123"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test2(){
	const char* str[] = {"123", "abc"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test3(){
	const char* str[] = {"ABC", "[]"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test4(){
	const char* str[] = {"[]", "abc"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test5(){
	const char* str[] = {"ab**", "ab12"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test6(){
	const char* str[] = {"a10", "b10"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test7(){
	const char* str[] = {"B10", "a10"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test8(){
	const char* str[] = {"a1.txt", "a1txt"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test9(){
	const char* str[] = {"2", "100"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test10(){
	const char* str[] = {"a10.txt", "a1.txt"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}
void test11(){
	const char* str[] = {"a9.txt", "a10.txt"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test12(){
	const char* str[] = {"a9abcd", "a10"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test13(){
	const char* str[] = {"0001", "1"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test14(){
	const char* str[] = {"&1", "&001"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}

void test15(){
	const char* str[] = {"002", "1"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}
void test16(){
	const char* str[] = {"002ab", "1ab"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}

void test17(){
	const char* str[] = {"abc123", "abc123"};
	printf("*%s*\n", (humane_strcmp(str, str+1) == 0) ? "PASS":"FAIL");
}
void test18(){
	const char* str[] = {"abc2", "abc001"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}
void test19(){
	const char* str[] = {"ab1", "abc1"};
	printf("*%s*\n", (humane_strcmp(str, str+1) < 0) ? "PASS":"FAIL");
}
void test20(){
	const char* str[] = {"ab1", "ab&1"};
	printf("*%s*\n", (humane_strcmp(str, str+1) > 0) ? "PASS":"FAIL");
}

void sort_test1(){
	const char* list[] = {
		"a1.txt",
		"a2.txt",
		"a9.txt",
		"a10.txt",
		"1.txt",
		"001.txt",
		"a123.txt",
		"bsdfsdf123233",
		"A10",
		"B1",
		"b13",
		"002"
	};
	humane_sort(list, 12);
	print_strings(list, 12);
}

int main(){
	int i;
	test_ptr_t strcmp_tests[NUM_STRCMP_TESTS] = {test0,  test1,  test2,  test3,  test4,  
		                                         test5,  test6,  test7,  test8,  test9,
												 test10, test11, test12, test13, test14, 
												 test15, test16, test17, test18, test19,
												 test20};

	//test_ptr_t sort_tests[NUM_SORT_TESTS] = {sort_test1};

	// Run all humane_strcmp() tests
	for (i = 0;i<NUM_STRCMP_TESTS;i++){
		printf(" TEST %d: ", i);
		(*strcmp_tests[i])();
	}

	sort_test1();

	return 0;
}
