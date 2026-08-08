/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:48:08 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/28 21:30:49 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks ranks from the top toward the bottom of the stack. */
int	stack_is_sorted_asc(t_stack *stack)
{
	int	index;

	index = 1;
	while (index < stack->depth)
	{
		if (rank_at(stack, index - 1) > rank_at(stack, index))
			return (0);
		index++;
	}
	return (1);
}

/*Returns the rank stored at a logical stack index. */
int	rank_at(t_stack *stack, int logical_index)
{
	t_node	*cur;
	int		i;

	if (!stack || !stack->top)
		return (0);
	if (logical_index < 0 || logical_index >= stack->depth)
		return (0);
	cur = stack->top;
	i = 0;
	while (i < logical_index)
	{
		cur = cur->next;
		i++;
	}
	return (cur->rank);
}

/* Finds the logical index of the smallest rank in a stack. */
int	smallest_rank_index(t_stack *stack)
{
	int	index;
	int	smallest_index;

	index = 1;
	smallest_index = 0;
	while (index < stack->depth)
	{
		if (rank_at(stack, index) < rank_at(stack, smallest_index))
			smallest_index = index;
		index++;
	}
	return (smallest_index);
}

/* Finds the logical index of the largest rank in a stack. */
int	largest_rank_index(t_stack *stack)
{
	int	index;
	int	largest_index;

	index = 1;
	largest_index = 0;
	while (index < stack->depth)
	{
		if (rank_at(stack, index) > rank_at(stack, largest_index))
			largest_index = index;
		index++;
	}
	return (largest_index);
}

/* Returns positive rotate steps or negative reverse-rotate steps. */
int	rotations_to_top(t_stack *stack, int logical_index)
{
	int	rotate_count;
	int	reverse_count;

	rotate_count = logical_index;
	reverse_count = stack->depth - logical_index;
	if (rotate_count <= reverse_count)
		return (rotate_count);
	return (-reverse_count);
}
