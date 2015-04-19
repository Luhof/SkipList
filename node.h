typedef struct node{

	int value;
	//pointer on pointers 
	struct node* nextNode[4];

} node;

node* createNode(int value, int maxLevel);
node* createHeadNode(int maxLevel);
node* createList(int *array, int size);
node* createEmptyNode(int maxLevel);
node* searchNodeFromList(node * firstNode, int key, int maxLevel);
