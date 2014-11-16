#include <stdio.h>
#include <stdlib.h>
#include "humane_sort.h"

#define MAX_LINE_LENGTH	100
#define MAX_NUM_LINES	300

/* 
 * Usage: humane_sort file.txt
 *        humane_sort < file.txt
 *        cat file.txt | humane_sort
 *        ls | humane_sort
 */
int main(int argc, char *argv[]){
	int i = 0;
	int j = 0;
	int read_from_file = 0;
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
	
	// If a filename is specified, read strings file
	if (argv[1]){
		FILE * fp;
		fp = fopen(argv[1],"r");
		if (fp == NULL){
			fprintf(stderr,"Error opening file.");
			fclose(fp);
			exit(1);
		}
		while (i < MAX_NUM_LINES){
			if (fscanf(fp, "%s", str_list[i]) == EOF){
				break;
			}
			i++;
		}
		fclose(fp);
	// Otherwise, read strings from stdin
	} else {
		while (i < MAX_NUM_LINES){
			if (scanf("%s", str_list[i]) == EOF){
				break;
			}
			i++;
		}
	}

	humane_sort((const char **)str_list, i);

	print_strings((const char **)str_list,i);

	// Free strings
	for (j = 0;j<MAX_NUM_LINES;j++){
		free(str_list[j]);
	}
	free(str_list);
	
	return 0;
}