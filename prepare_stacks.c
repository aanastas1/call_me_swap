/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 13:15:38 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_node **node, int value, int rank)
{
	t_node	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->rank = rank;
	if (*node == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		*node = tmp;
		return (1);
	}
	tmp->next = *node;
	tmp->prev = (*node)->prev;
	(*node)->prev->next = tmp;
	(*node)->prev = tmp;
	return (1);
}

static void	stacks_init(t_context *context, int *values, int *ranks, int cap)
{
	int	i;

	i = 0;
	while (i < cap)
	{
		if (!add_node(&context->a.top, values[i], ranks[i]))
		{
			free_stack(&context->a);
			return ;
		}
		context->a.depth++;
		i++;
	}
}

static int	validate_no_dups(int *values, int n)
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

static int	*compute_ranks(const int *values, int size)
{
	int	i;
	int	j;
	int	*ranks;

	ranks = xalloc(size, sizeof(int));
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ranks[i] = 0;
		j = 0;
		while (j < size)
		{
			if (values[j] < values[i])
				ranks[i]++;
			j++;
		}
		i++;
	}
	return (ranks);
}

void	setup_stacks(t_context *context, int *out_values, int size)
{
	int	*ranks;

	if (!validate_no_dups(out_values, size))
		return ;
	ranks = compute_ranks(out_values, size);
	if (!ranks)
		return ;
	stacks_init(context, out_values, ranks, size);
	free(ranks);
}
