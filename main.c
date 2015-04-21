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

	file = fopen("file.rtf", "r");
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

	printf("----INSERING SOME NODES YO------\n");
	insertNode(&list, 2, 1);
	insertNode(&list, 5, 42);
	printList(&list);

	printf("----SEARCHING NODE AT KEY 2------\n");
	node *searched = searchNodeFromList(&list, 2);
	if(searched){
		printf("node %d found, its value is %d !\n", searched->key, searched->value);
	}
	else{
		printf("node not found\n");
	}

	printf("----SEARCHING NODE AT KEY 3------\n");
	searched = searchNodeFromList(&list, 2);
	if(searched){
		printf("node %d found, its value is %d !\n", searched->key, searched->value);
	}
	else{
		printf("node not found\n");
	}

	printf("----SEARCHING NODE AT KEY 5------\n");
	searched = searchNodeFromList(&list, 5);
	if(searched){
		printf("node %d found, its value is %d !\n", searched->key, searched->value);
	}
	else{
		printf("node not found\n");
	}

	free(list.header->nextNode);
	free(list.header);
	printf("list is free - (have to try valgrind to it)\n");

	return 0;
}
