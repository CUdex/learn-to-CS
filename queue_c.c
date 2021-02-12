#include <stdio.h>
#define MAXSIZE 10

int queue[MAXSIZE];
int front, rear;

void	init_queue(void)
{
	front = rear = 0;
}

void	clear_queue(void)
{
	front = rear;
}

int		put(int val)
{
	// 큐가 꽉 찼는지 확인
	if ((rear + 1) % MAXSIZE == front)
	{
		printf("queue Overflow\n");
		return (-1);
	}
	queue[rear] = val;
	rear = ++rear % MAXSIZE;
	return val;
}

int		get(void)
{
	int i;

	// 큐가 비어있는 지 확인
	if (front == rear)
	{
		printf("queue Underflow\n");
		return (-1);
	}
	i = queue[front];
	front = ++front % MAXSIZE;
	return (i);
}

void	print_queue(void)
{
	printf("queue From Front ---------> To Rear\n");
	for (int i = front; i != rear; i = ++i % MAXSIZE)
		printf("%-6d", queue[i]);
}

int     main(void)
{
    init_queue();
	put(1);
	put(2);
	put(3);
	put(4);
	put(5);

	put(6);
	put(7);
	put(8);
	put(9);
	put(10);
	print_queue();

	printf("%d\n",get());
	print_queue();
}
