#ifndef LIST_H
#include "list.h"
#endif

void initList(skipList *list){

	int i;
	
	list->header = calloc(1, sizeof(node));
	list->header->key = MAX_INT;

	//le niveau (hauteur) de la liste ne prend pas en compte le header
	//ce niveau sera modifié au fil du temps (lors des insert) afin d'obtenir le niveau maximal du moment
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

node * insertNode(skipList *list, int key, int value){
	node *x = list->header;
	node *update[MAX_LEVEL-1];

	//searching for emplacement to insert (like searchNode)
	int i;
	for(i = list->level-1; i>0; i--){
		while(x->nextNode[i]->key < key){
			x = x->nextNode[i];
		}
		update[i] = x;
	}

	x = x->nextNode[0];

	//si la key existe déjà on remplace sa valeur
	
	if(x!=NIL && x->key == key){
		x->value = value;
		return x;
	}
	else{
		//need to code this function
		int level = randLevel(MAX_LEVEL, 1/2);

		if(level > list->level){
			for(i = list->level; i<level; i++){
				update[i] = list->header;
			}
			list->level = level;
		}

		//creating an empty node
		x = calloc(1, sizeof(node));
		x->key = key;
		x->value = value;
		x->nextNode = calloc(1, sizeof(node)*level);

		//on applique les modifs
		for(i=0; i<level; i++){
			x->nextNode[i] = update[i]->nextNode[i];
			update[i]->nextNode[i] = x;
		}
	}

	return x;

}

node * DeleteNode(skipList *list, int key) {

node *x = list->header;
node *update[MAX_LEVEL-1];

int i;

	for (i= list->level-1;i<0;i--) {

		while(x->nextNode[i]-> key < key) {
		x = x->nextNode[i];
		}

	update[i] = x;
	}

x = x->nextNode[0];
int level = list->level;

	if (x->key == key) {

		for(i=0;i>=list->level-1;i++) {

			if(update[i]->nextNode[i] != x) {

				exit(1);
			}
			update[i]->nextNode[i] = x->nextNode[i];
		}
		free(x);

		while (level>0 && list->header->nextNode[level-1] == NIL) {

			list->level = level-1;
		}

}

	return x; 
}

int randLevel(int maxLevel, float p){
	int level = 0;
	srand(time(NULL));

	//weird random shiet;
	float randLvl = rand() % 2;
	printf("f = %f\n", randLvl);
	while((randLvl<p) && (level<maxLevel)){
		level++;
		printf("yay rand is %f\n", randLvl);
		randLvl = rand();
	}
	printf("level : %d\n", level);
	return level;
}

node * searchNodeFromList(skipList *list, int key){
	node * x = list->header;
	int i;
	for(i=list->level; i>0; i--){

		while(x->nextNode[i]->key < key){
			x = x->nextNode[i];
		}
	}
	if(x->key == key){
		return x;
	}
	else{
		return NULL;
	}
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





