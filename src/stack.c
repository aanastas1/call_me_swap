#include "push_swap.h"

int	stack_init(t_stack *stack, int capacity)
{
	if (capacity < 0)
    	return (0);
	stack->numbers = NULL;
	stack->size = 0;
	stack->capacity = capacity;
	if (capacity == 0)
		return (1);
	stack->numbers = malloc(sizeof(*stack->numbers) * capacity);
	if (stack->numbers == NULL)
	{
		stack->capacity = 0;
		return (0);
	}
	return (1);
}

void	stack_clear(t_stack *stack)
{
	free(stack->numbers);
	stack->numbers = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

int	stack_is_empty(const t_stack *stack)
{
	if (stack->size == 0)
		return(1); // стек пустой
	else
		return (0); // в стеке есть элементы
}

int	stack_is_sorted_asc(const t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i - 1].rank > stack->numbers[i].rank)
			return (0); // stack не отсортирован
		i++;
	}
	return (1); // полностью отсортирован
}
/* 
int	main(void)
{
	t_stack		a;
	t_number	removed;

	if (!stack_init(&a, 3))
		return (1);
	stack_add_top(&a, 20, 2);
	stack_add_top(&a, 30, 1);
	stack_add_top(&a, 10, 0);
	printf("Stack: %d, %d, %d", a.numbers[0].value, a.numbers[1].value, a.numbers[2].value);
	printf("top: 		value=%d, rank=%d\n", a.numbers[0].value, a.numbers[0].rank);
	printf("after pushes: 	empty=%d, sorted=%d, size=%d\n",
		stack_is_empty(&a), stack_is_sorted_asc(&a), a.size);
	if (stack_remove_top(&a, &removed))
		printf("popped: 	value=%d, rank=%d\n", removed.value, removed.rank);
	printf("after pop: 	empty=%d, sorted=%d, size=%d\n",
		stack_is_empty(&a), stack_is_sorted_asc(&a), a.size);
	stack_clear(&a);
	printf("after clear: 	empty=%d, size=%d\n", stack_is_empty(&a), a.size);
	return (0);
}
	*/