/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/18 15:51:28 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stacks_init(t_context *context, int capacity)
{
	context->a.elements = xalloc(capacity, sizeof(t_element));
	context->a.depth = capacity;
	context->b.elements = xalloc(capacity, sizeof(t_element));
	context->b.depth = 0;
}

int	validate_no_dups(int *values, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

double	compute_disorder_values(const int *values, int n)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total_pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}

void	compute_ranks(t_context *context, const int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		context->a.elements[size - 1 - i].rank = 0;
		j = 0;
		while (j < size)
		{
			if (values[j] < values[i])
				context->a.elements[size - 1 - i].rank++;
			j++;
		}
		i++;
	}
}

void	setup_stacks(t_context *context, int *values, int size)
{
	int	i;

	stacks_init(context, size);
	compute_ranks(context, values, size);

    i = 0;
	while (i < size)
	{
    	context->a.elements[i].value = values[size - 1 - i];
    	i++;
	}
}
