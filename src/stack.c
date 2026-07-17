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