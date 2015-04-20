#ifndef LIST_H
#include "list.h"
#endif

void initList(skipList *list){

	int i;
	
	list->header = calloc(1, sizeof(node));
	list->header->key = MAX_INT;

	//le niveau (hauteur) de la liste ne prend pas en compte le header
	list->level = 0;

	if((list->header->nextNode = calloc(1, sizeof(node*) * MAX_LEVEL)) == 0){
        printf("Error w/ memory\n");
        exit(EXIT_FAILURE);
    }

    //les 4 pointeurs du header pointent sur null
    for(i=0; i<MAX_LEVEL; i++){
    	list->header->nextNode[i] = NIL;
    }

}

void printList(skipList *list){

	//ne marche pas très bien pour le moment

	/*node * tempNode = firstNode;
	while(tempNode->nextNode[0] != NULL){
		printf("%d -> ", tempNode->value);
		tempNode = tempNode->nextNode[0];
	}
	printf("\n");*/
}

node * searchNodeFromList(skipList *list, int key){
	return NULL;
}

void freeList(skipList *list){
	//doesn't work =(

	/*printf("deleting node\n");
	freeNode(list->header->nextNode);
	printf("deleted node\n");
	free(list->header);*/
}

void freeNode(node *node){

	//doesn't work =(

	/*printf("yaaay\n");
	if(node){
		printf("lolmdr\n");
		free(node->nextNode);
		free(node);
	}*/ 
}





