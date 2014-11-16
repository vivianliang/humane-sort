#include <stdio.h>
#include <stdlib.h>
#include "humane_sort.h"

#define MAX_LINE_LENGTH	50
#define MAX_NUM_LINES	100

// Usage: ./humane_sort file.txt
int main(int argc, char *argv[]){
	int i = 0;
	int j = 0;	
	char** str_list = NULL;

	// Allocate space for strings
	str_list =  (char**)malloc(sizeof(char*) * MAX_NUM_LINES);
	if (str_list == NULL){
		fprintf(stderr,"out of memory");
		exit(1);
	}
	for (j = 0;j<MAX_NUM_LINES;j++){
		str_list[j] = (char*)malloc(sizeof(char)*(MAX_LINE_LENGTH+1));
	}
	
	// Read strings file
	FILE * fp;
	fp = fopen(argv[1],"r");
	if (fp == NULL){
		fprintf(stderr,"error opening file");
		fclose(fp);
		exit(1);
	}
	while (i < MAX_NUM_LINES){
		if (fscanf(fp, "%s", str_list[i])==EOF){
			break;
		}
		i++;
	}

	humane_sort((const char **)str_list, i);

	print_strings((const char **)str_list,i);

	fclose(fp);

	// Free strings
	for (j = 0;j<MAX_NUM_LINES;j++){
		free(str_list[j]);
	}
	free(str_list);
	
	return 0;
}