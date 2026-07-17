/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:40:42 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/17 10:40:43 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rank_at(t_arr *stack, int logical_idx)
{
	return (stack->elements[phys_idx(stack, logical_idx)].rank);
}

static int	min_rank_index(t_arr *stack)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < stack->depth)
	{
		if (rank_at(stack, i) < rank_at(stack, min_index))
			min_index = i;
		i++;
	}
	return (min_index);
}

static void	move_min_to_b(t_context *context)
{
	int	min_index;
	int	from_top;

	min_index = min_rank_index(&context->a);
	from_top = context->a.depth - 1 - min_index;
	if (from_top <= context->a.depth / 2)
		while (from_top-- > 0)
			ra(context);
	else
	{
		min_index++;
		while (min_index-- > 0)
			rra(context);
	}
	pb(context);
}

static void	sort_three(t_context *context)
{
	int	top;
	int	middle;
	int	bottom;

	top = rank_at(&context->a, 2);
	middle = rank_at(&context->a, 1);
	bottom = rank_at(&context->a, 0);
	if (top > middle && top > bottom)
		ra(context);
	else if (middle > top && middle > bottom)
		rra(context);
	if (rank_at(&context->a, 2) > rank_at(&context->a, 1))
		sa(context);
}

void	sort_small(t_context *context)
{
	if (context->a.depth < 2 || stack_is_sorted_asc(&context->a))
		return ;
	if (context->a.depth == 2)
	{
		sa(context);
		return ;
	}
	while (context->a.depth > 3)
		move_min_to_b(context);
	sort_three(context);
	while (context->b.depth > 0)
		pa(context);
}
