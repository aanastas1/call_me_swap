/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 19:30:21 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Two-Stack Quicksort */
static void	side_a(t_context *context, int min_rank, int max_rank);
static void	side_b(t_context *context, int min_rank, int max_rank);

static void	push_it_b(t_context *context, int min, int max, int *top_rank)
{
	int	delimiter;
	int	count;

	delimiter = (min + max) / 2;
	count = delimiter - min;
	while (count)
	{
		if (context->a.top->rank < delimiter)
		{
			pb(context);
			count--;
		}
		else
		{
			if (*top_rank == -1)
				*top_rank = context->a.top->rank;
			ra(context);
		}
	}
}

static void	side_a(t_context *context, int min_rank, int max_rank)
{
	int	delimiter;
	int	start_rank;
	int	range;

	range = max_rank - min_rank + 1;
	if (range == 1)
		return ;
	if (range == 2)
	{
		if (context->a.top->rank > context->a.top->next->rank)
			sa(context);
		return ;
	}
	delimiter = (min_rank + max_rank) / 2;
	start_rank = -1;
	push_it_b(context, min_rank, max_rank, &start_rank);
	if (start_rank != -1)
	{
		while (context->a.top->rank != start_rank)
			rra(context);
	}
	side_a(context, delimiter, max_rank);
	side_b(context, min_rank, delimiter - 1);
}

static void	push_it_a(t_context *context, int max, int delimiter)
{
	int	count;
	int	start_rank;

	start_rank = -1;
	count = max - delimiter + 1;
	while (count)
	{
		if (context->b.top->rank >= delimiter)
		{
			pa(context);
			count--;
		}
		else
		{
			if (start_rank == -1)
				start_rank = context->b.top->rank;
			rb(context);
		}
	}
	if (start_rank != -1)
	{
		while (context->b.top->rank != start_rank)
			rrb(context);
	}
}

static void	side_b(t_context *context, int min_rank, int max_rank)
{
	int	delimiter;
	int	range;

	range = max_rank - min_rank + 1;
	if (range == 1)
	{
		pa(context);
		return ;
	}
	if (range == 2)
	{
		if (context->b.top->rank < context->b.top->next->rank)
			sb(context);
		pa(context);
		pa(context);
		return ;
	}
	delimiter = (min_rank + max_rank + 1) / 2;
	push_it_a(context, max_rank, delimiter);
	side_a(context, delimiter, max_rank);
	side_b(context, min_rank, delimiter - 1);
}

void	strategy_complex(t_context *context)
{
	int	min_rank;
	int	max_rank;

	context->strategy_name = "Complex";
	context->complexity = "O(nlog(n))";
	min_rank = 0;
	max_rank = context->a.depth - 1;
	side_a(context, min_rank, max_rank);
}
