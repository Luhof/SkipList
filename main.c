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

	//Lecture d'un fichier (!) test (!) 

	FILE* file = NULL;

	file = fopen("file.txt", "r");
	char currentChar;

	if(!file) {

		printf("sorry I can't open the file lol too bad \n");
	}

	else {

		//instructions de lecture ou d'écriture 
		printf("LECTURE DU FICHIER :\n");
		do {
			currentChar = fgetc(file);
			printf("%c",currentChar);
		}
		while(currentChar != EOF);

		// on ferme le fichier : 
		fclose(file);

	}


	srand(time(NULL));

	skipList list;
	initList(&list);

	printf("\n\n----INSERING SOME NODES YO------\n");
	insertNode(&list, 2, 1);
	insertNode(&list, 5, 42);
	insertNode(&list, 7, 3);
	insertNode(&list, 3, 20);
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
