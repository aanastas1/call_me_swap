/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:40:42 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/25 19:00:57 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves the smallest rank in stack A to stack B. */
static void	push_smallest_to_b(t_context *context)
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
	pb(context);
}

/* Sorts exactly three elements in stack A. */
static void	sort_three(t_context *context)
{
	int	top;
	int	middle;
	int	bottom;

	top = rank_at(&context->a, 0);
	middle = rank_at(&context->a, 1);
	bottom = rank_at(&context->a, 2);
	if (top > middle && top > bottom)
	{
		ra(context);
		//print_stack_a_b(context);
	}
	else if (middle > top && middle > bottom)
	{
		rra(context);
		//print_stack_a_b(context);
	}
	if (rank_at(&context->a, 0) > rank_at(&context->a, 1))
	{
		sa(context);
		//print_stack_a_b(context);
	}
}

/* Sorts up to five elements in A and restores saved values from B. */
void	sort_small(t_context *context)
{
	if (context->a.depth > 1 && !stack_is_sorted_asc(&context->a))
	{
		if (context->a.depth == 2)
		{
			sa(context);
			//print_stack_a_b(context);
		}
		else
		{
			while (context->a.depth > 3)
				push_smallest_to_b(context);
			printf("DEBUG:     before sort_three\n");
			print_stack_a_b(context);
			sort_three(context);
			printf("DEBUG:     after sort_three\n");
			print_stack_a_b(context);
		}
	}
	while (context->b.depth > 0)
	{
		pa(context);
		//print_stack_a_b(context);
	}
}
