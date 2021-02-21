#include <stdio.h>
#include <stdlib.h>

bucket *hashTable = NULL;

typedef struct node
{
	int key;
	int value;

	struct node *next;
} node;

typedef struct bucket
{
	struct node *head;
	int count;
} bucket;

node *createNode(int key, int value)
{
	node *newNode;

	newNode = (node *)malloc(sizeof(node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return (newNode);
}
insert
remove
search
display

int		main(void)
{
	return (0);
}
