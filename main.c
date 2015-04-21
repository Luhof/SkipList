#define NIL NULL
#define MAX_LEVEL 4
#define MAX_INT 10000


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LIST_H
	#include "list.h"
#endif





int main(int argc, char *argv[]){

	srand(time(NULL));

	skipList list;
	initList(&list);
	printf("initiated list\n");

	insertNode(&list, 2, 1);
	insertNode(&list, 5, 42);
	printf("node inserted\n");
	printList(&list);
	node *searched = searchNodeFromList(&list, 2);
	
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
