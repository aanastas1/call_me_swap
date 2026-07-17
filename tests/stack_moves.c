#include "push_swap.h"

int	stack_remove_top(t_stack *stack, t_element *out)
{
	if (stack->size == 0)
		return (0);
	if (out != NULL)
		*out = stack->numbers[0];
	stack->size--;
	memmove(stack->numbers, stack->numbers + 1,
		sizeof(*stack->numbers) * stack->size);
	return (1);
}

int	stack_add_top(t_stack *stack, int value, int rank)
{
	if (stack->size == stack->capacity)
		return (0);
	memmove(stack->numbers + 1, stack->numbers,
		sizeof(*stack->numbers) * stack->size);
	stack->numbers[0].value = value;
	stack->numbers[0].rank = rank;
	stack->size++;
	return (1);
}
