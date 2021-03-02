#include <stdio.h>
#include <stdlib.h>

int SIZE = 10;

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

bucket *hashTable = NULL;

//node 생성
node *createNode(int key, int value)
{
	node *newNode;

	newNode = (node *)malloc(sizeof(node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return (newNode);
}

/* bucket 위치 알려주는 함수 */
int	hashFunction(int key)
{
	return (key%SIZE);
}

// 넣고자 하는 key와 vlaue를 만들어줌
void insert(int key, int value)
{
	// 들어갈 버킷 위치 생성
	int hashIndex = hashFunction(key);

	// 노드 생성
	node *newNode = createNode(key, value);

	// 넣고자 하는 값이 버켓 안의 노드에 없는 경우
	if (hashTable[hashIndex].count == 0)
	{
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count = 1;
	}
	// 버킷 안에 노드가 존재하는 경우
	else
	{
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}
}

/* 노드 삭제 */
void ft_remove(int key)
{
	int hashIndex = hashFunction(key);

	node *trace;
	node *node;

	node = hashTable[hashIndex].head;

	// 버켓 안에 지우고자 하는 노드가 없을 경우.
	if (node == NULL)
	{
		// 아무것도 없음을 알린다.
		printf("\n no key found");
		return ;
	}
	while (node != NULL)
	{
		if (node->key == key)
		{
			// 포인터를 바꿔주는 작업.
			if (node == hashTable[hashIndex].head)
				hashTable[hashIndex].head = node->next;
			else
				trace->next = node->next;

			hashTable[hashIndex].count--;
			free(node);
			return ;
		}
		// 하나 전 노드의 포인터를 저장
		trace = node;
		node = node->next;
	}
	// 찾는 값이 노드 안에 없을 경우
	printf("\n not key found");
	return ;
}

/* 원하는 노드를 찾는 과정 */
void search(int key)
{
	int hashIndex = hashFunction(key);
	node *node = hashTable[hashIndex].head;

	if (node == NULL)
	{
		printf("\nno key found");
		return ;
	}
	while (node != NULL)
	{
		if (node->key == key)
		{
			printf("key found key = [%d] value = [%d] ",node->key, node->value);
			return ;
		}
		node = node->next;
	}

	printf("\nno key found");
	return ;
}
void display(void)
{
	node *horse;
	int i = 0;

	for(i = 0; i < SIZE; i++)
	{
		horse = hashTable[i].head;
		printf("Bucket[%d] : ", i);
		
		while (horse != NULL)
		{
			printf("key : %d , val : %d -> ", horse->key, horse->value);
			horse = horse->next;
		}
		printf("\n");
	}
	printf(" -----end of display-------\n");
	return ;
}

int		main(void)
{
	// 버킷 생성
	hashTable = (bucket *)malloc(SIZE * sizeof(bucket));

	insert(0, 1);
	insert(1, 10);
	insert(11, 10);
	insert(21, 10);
	insert(31, 10);
	insert(6, 25);
	insert(97, 29);

	display();

	search(97);
	search(25);

	ft_remove(31);
	ft_remove(11);

	display();
	return (0);
}
