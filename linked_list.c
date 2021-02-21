#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}	n_node;

/* 헤더 생성 */
n_node *create_head(void)
{
	n_node *head = (n_node *)malloc(sizeof(n_node));
	head->next = NULL;
	return (head);
}

/* 리스트 끝에 노드 추가 */
n_node *add_list(n_node *list, int data)
{
	if (list == NULL)
		return (0);
	// 끝 노드로 이동
	while (list->next)
		list = list->next;
	list->next = (n_node *)malloc(sizeof(n_node));
	list = list->next;
	list->data = data;
	list->next = NULL;
	return (list);
}

/* 리스트 길이 파악 */
int	size_node(n_node *list)
{
	int len = 0;
	while (list->next)
	{
		list = list->next;
		len++;
	}
	return (len);
}

/* 원하는 순서에 있는 노드 데이터 출력 */
n_node	*print_list(n_node *list, int idx)
{
	int i = 0;
	int len = size_node(list);
	if (list == NULL)
		printf("빈 노드입니다.");
	if (idx > len)
	{
		printf("리스트 범위 밖입니다.");
		return (NULL);
	}
	while (i < idx)
	{
		list = list->next;
		i++;
	}
	printf("%d번째 노드의 데이터 값은%d입니다.", idx, list->data); 
	return (list);
}

void	node_clear(n_node *list)
{
	n_node *curr_list;

	while (list)
	{
		curr_list = list->next;
		free(list);
		list = curr_list;
	}
}

int		main(void)
{	
	n_node *first = create_head(); 
	add_list(first, 1);
	add_list(first, 2);
	add_list(first, 3);
	add_list(first, 4);
	add_list(first, 5);
	add_list(first, 6);
	add_list(first, 7);
	add_list(first, 8);
	add_list(first, 9);

	print_list(first, 3);
	node_clear(first);
	return (0);
}
