#define NIL NULL
#define MAX_LEVEL 3
#define MAX_INT 99999


#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
	#include "list.h"
#endif





int main(int argc, char *argv[]){

	skipList list;
	initList(&list);
	printf("initiated list\n");
	free(list.header->nextNode);
	free(list.header);
	printf("list is free - (have to try valgrind to it)\n");

	return 0;
}