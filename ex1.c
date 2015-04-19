#include <stdio.h>
#include <stdlib.h>

#include "node.h"

void printList(node * firstNode);
void freeList(node * firstNode);
int lengthList(node * firstNode);

void printList(node * firstNode){
	node * tempNode = firstNode;
	while(tempNode->nextNode[0] !=NULL){
		printf("%d -> ", tempNode->value);
		tempNode = tempNode->nextNode[0];
	}
	printf("\n");
}

void printFullList(node * firstNode){
	node * tempNode = firstNode;
	while(tempNode->nextNode[3] != NULL){
		printf("%d -> ", tempNode->value);
		tempNode = tempNode->nextNode[3];
	}

	printf("%d.\n", tempNode->value);	
}

void freeList(node * firstNode){

	node * tempNode = firstNode;
	do{
		free(tempNode);
		tempNode = tempNode->nextNode[0];
	}
	while(tempNode->nextNode[0]!=NULL);
	free(tempNode);
}

int lengthList(node * firstNode){

	int i=0;
	node * tempNode = firstNode;
	//printf("tempNode = %d", tempNode->nextNode->value);
	while(tempNode->nextNode[0] !=NULL){
		tempNode = tempNode->nextNode[0];
		i++;
	}
	return i;
}

int main(int argc, char *argv[]){

	int maxLevel = 3;
	int arraySize = 10;

	node * firstNode = createHeadNode(maxLevel);
	
	printFullList(firstNode);
	node * foundNode = searchNodeFromList(firstNode, 3, maxLevel);

	return 0;
}