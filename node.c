#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node* createNode(int value, int maxLevel){

	node* newNode = (node*)calloc(1, sizeof(node));
	newNode -> value = value;

	int i;
	for(i=0; i<maxLevel; i++)
		newNode -> nextNode[i] = NULL;

	return newNode;

}

node* createEmptyNode(int maxLevel){

	node* newNode = (node*)calloc(1, sizeof(node));

	int i;
	for(i=0; i<maxLevel; i++)
		newNode -> nextNode[i] = NULL;

	newNode->value = 0;
	return newNode;

}

node* createHeadNode(int maxLevel){

	node * newNode = createEmptyNode(maxLevel);
		
	node * node2 = createNode(3, 4);

	//here I manually inserted first node.

	//todo : automation.
	newNode->nextNode[0] = node2;

	newNode->value = 0;
	return newNode;

}

node* createList(int *array, int size){

	int i=0;
	node* tempNode = NULL;
	node * newNode = NULL;

	for(i=size; i>=0; i--){
		newNode = createNode(array[i], 4);
		newNode->nextNode[0] = tempNode;
		tempNode = newNode;
	}
	return newNode;

}

node* searchNodeFromList(node * firstNode, int key, int maxLevel){

	//Segmentation fault :/ valgrind might help ?
	node * x = firstNode;

	int i;
	for(i=maxLevel; i>0; i--){

		printf("i = %d - xVal : %d\n", i, x->value);

		printf("next value : %d\n", x->nextNode[i]->value);
		while(x->nextNode[i]->value < key){
			printf("hello\n");
			x = x->nextNode[i];
		}
		printf("ended step %d\n", i);
	}

	x = x->nextNode[0];

	if(x->value==key)
		return x;
	else
		return NULL;

}