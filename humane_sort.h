#ifndef HUMANE_SORT_H
#define HUMANE_SORT_H

void humane_sort(const char** str_list, unsigned long long num_elements);
void print_sorted_strings(const char** str_list, unsigned long long num_elements);

// This function is exposed here for testing purposes
int humane_strcmp(const void *a, const void *b);


#endif
