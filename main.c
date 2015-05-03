//this code is also available on my github : https://github.com/Luhof/SkipList

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

	if(argc>1){
		initializeFromFile(&list, argv[1]);
	}
	else{
		printf("\n****\nTo import a file run ./prog pathtofile.txt\nuse file.txt or file.csv :)\n****\n");

		printf("\n\n----INSERING SOME NODES ------\n");
		insertNode(&list, 2, 1);
		insertNode(&list, 5, 42);
		insertNode(&list, 7, 3);
		insertNode(&list, 3, 20);
	}

	printList(&list);

	printf("\n\n----SEARCHING NODE AT KEY 2------\n");
	node * searched = searchNodeFromList(&list, 2);
	if(searched){
		printf("node %d found, its value is %d !\n", searched->key, searched->value);
	}
	else{
		printf("node not found\n");
	}

	printf("\n----DELETING NODE AT KEY 2----");
	deleteNode(&list, 2);

	printf("\n\n----SEARCHING NODE AT KEY 5------\n");
	searched = searchNodeFromList(&list, 5);
	if(searched){
		printf("node %d found, its value is %d !\n", searched->key, searched->value);
	}
	else{
		printf("node not found\n");
	}

	printList(&list);

	freeList(&list);

	printf("(list is free - valgrinded with 0 bytes lost)\n");

	return 0;
}
