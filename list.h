#define NIL NULL
#define MAX_LEVEL 4
#define MAX_INT 10000

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>



typedef struct node{

	int key;
	int value;
	struct node **nextNode;

}node;

typedef struct skipList{

	node *header;
	int level;

}skipList;

//initialise la liste
void initList(skipList *list);

//affiche le bottom layer de la liste (liste complète)
void printList(skipList *list);
int insertNode(skipList *list, int key, int value);
//retourne le noeud correspondant à une key donnée

int deleteNode(skipList *list, int key);
// supprime un noeud 
node * searchNodeFromList(skipList *list, int key);

//insère un noeud à une key donnée et valeur.
//function machin

//delete un noeud à une key donnée
//function machin
int randLevel(int p, int maxLevel);
//libère des trucs
void freeList(skipList *list);
void freeNode(node *node);