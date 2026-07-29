/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:00:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/25 18:48:13 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves the smallest rank in A to its top by the shorter path. */
static void	move_smallest_to_top(t_context *context)
{
	int	steps;

	steps = rotations_to_top(&context->a,
			smallest_rank_index(&context->a));
	while (steps > 0)
	{
		ra(context);
		steps--;
	}
	while (steps < 0)
	{
		rra(context);
		steps++;
	}
}

/* Applies selection sort by extracting minimum ranks into stack B. */
void	strategy_simple(t_context *context)
{
	context->strategy_name = "Simple";
	context->complexity = "O(n^2)";
	if (stack_is_sorted_asc(&context->a))
		return ;
	while (context->a.depth > 5)
	{
		move_smallest_to_top(context);
		pb(context);
	}
	sort_small(context);
}
