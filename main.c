#define NIL NULL
#define MAX_LEVEL 3
#define MAX_INT 10000


#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
	#include "list.h"
#endif





int main(int argc, char *argv[]){

	skipList list;
	initList(&list);
	printf("initiated list\n");

	insertNode(&list, 1, 1);
	node * searched = searchNodeFromList(&list, 1);
	if(searched){
		printf("node found\n");
	}
	else{
		printf("node not found\n");
	}
	free(list.header->nextNode);
	free(list.header);
	printf("list is free - (have to try valgrind to it)\n");

	return 0;
}