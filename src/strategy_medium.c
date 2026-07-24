/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:40:50 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/23 12:26:26 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculates floor(sqrt(number)) */
static int	integer_square_root(int number)
{
	int	root;

	root = 1;
	while (root + 1 <= number / (root + 1))
		root++;
	return (root);
}

/* Pushes one accepted rank to B or rotates A to inspect another rank. */
static void	move_top_by_window(t_context *context, int *pushed_count,
		int window_size)
{
	int	rank;

	rank = rank_at(&context->a, 0);
	if (rank <= *pushed_count)
	{
		pb(context);
		print_stack_a_b(context);
		if (context->b.depth > 1)
		{
			rb(context);
	 		 print_stack_a_b(context);
		}
		(*pushed_count)++;
	}
	else if (rank <= *pushed_count + window_size)
	{
		pb(context);
		print_stack_a_b(context);
		(*pushed_count)++;
	}
	else
	{
		ra(context);
		 print_stack_a_b(context);
	}
}

/* Moves all ranks to B through a sliding rank window. */
static void	move_all_to_b(t_context *context, int element_count)
{
	int	pushed_count;
	int	window_size;

	pushed_count = 0;
	window_size = integer_square_root(element_count);
	window_size += window_size / 2 + 1;
	while (context->a.depth > 0)
		move_top_by_window(context, &pushed_count, window_size);
}

/* Moves the largest rank in B to its top by the shorter path. */
static void	move_largest_to_top(t_context *context)
{
	int	steps;

	steps = rotations_to_top(&context->b,
			largest_rank_index(&context->b));
	while (steps > 0)
	{
		rb(context);
		 print_stack_a_b(context);
		steps--;
	}
	while (steps < 0)
	{
		rrb(context);
		 print_stack_a_b(context);
		steps++;
	}
}

/* Applies a rank-window strategy with O(n * sqrt(n)) operations. */
void	strategy_medium(t_context *context)
{
	int	element_count;

	context->strategy_name = "Medium";
	context->complexity = "O(n*sqrt(n))";
	if (stack_is_sorted_asc(&context->a))
		return ;
	if (context->a.depth <= 5)
	{
		sort_small(context);
		return ;
	}
	element_count = context->a.depth;
	move_all_to_b(context, element_count);
	while (context->b.depth > 0)
	{
		move_largest_to_top(context);
		pa(context);
		 print_stack_a_b(context);
	}
}
