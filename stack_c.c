#include <stdio.h>
#include <stdlib.h>

int		push(int *istack, int *stack_idx, int *stack_max_size, int i)
{
	if ((*stack_idx) >= (*stack_max_size) - 1)
	{
		printf("스택에 빈 공간이 없습니다.\n");
		return (0);
	}
	(*stack_idx)++;
	*(istack + (*stack_idx)) = i;
	printf("%d : 스택에 저장되었습니다.\n", *(istack + (*stack_idx)));
	return (1);
}

int		pop(int *istack, int *stack_idx)
{
	if ((*stack_idx) < 0)
	{
		printf("스택에 저장된 데이터가 없습니다. \n");
		return (0);
	}
	printf("%d :  데이터 값을 가져옵니다.\n", *(istack + (*stack_idx)));
	(*stack_idx)--;	
	return (1);
}
int		main(void)
{
	/* 스택의 사이즈 설정 */
	int		stack_max_size = 20;
	int 	stack_idx = -1;
	int		*istack = NULL;

	istack = (int *)malloc(sizeof(int) * stack_max_size);
	for (int i = 1; i <= 22; i++)
		push(istack, &stack_idx, &stack_max_size, i);
	while (pop(istack, &stack_idx)){}

	free(istack);
}
