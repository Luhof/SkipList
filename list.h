#define NIL NULL
#define MAX_LEVEL 4
#define MAX_INT 10000
#define MAX_CHAR 100

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct node{

	int key;
	int value;
	struct node **nextNode;

}node;

typedef struct skipList{

	node *header;
	int level;

}skipList;


void initList(skipList *list);
void initializeFromFile(skipList *list, char *fileAdress);
void printList(skipList *list);
int insertNode(skipList *list, int key, int value);
int deleteNode(skipList *list, int key);
node * searchNodeFromList(skipList *list, int key);
int randLevel(int p, int maxLevel);
void freeList(skipList *list);
void freeNode(node *node);