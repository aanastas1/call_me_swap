/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:48:08 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:34 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the rank stored at a logical stack index. */
int	rank_at(t_arr *stack, int logical_index)
{
	return (stack->elements[logical_index].rank);
}

/* Finds the logical index of the smallest rank in a stack. */
int	smallest_rank_index(t_arr *stack)
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
int	largest_rank_index(t_arr *stack)
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
int	rotations_to_top(t_arr *stack, int logical_index)
{
	int	rotate_count;
	int	reverse_count;

	rotate_count = logical_index;
	reverse_count = stack->depth - logical_index;
	if (rotate_count <= reverse_count)
		return (rotate_count);
	return (-reverse_count);
}
