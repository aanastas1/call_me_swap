/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/24 22:56:46 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_node(t_node **node, int value, int rank)
{
	t_node *tmp;

	tmp = malloc(sizeof(*tmp));
	if(!tmp)
		put_error_n_exit();
	tmp->value = value;
	tmp->rank = rank;
	printf("DEBUG add_node: node=%p\n", (void*)node);
	if (*node == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		*node = tmp;
		return ;
	}

	// вставка между (*top)->prev и *top
	tmp->next = *node;
	tmp->prev = (*node)->prev;
	(*node)->prev->next = tmp;
	(*node)->prev = tmp;

}

static void	stacks_init(t_context *context, int *out_values, int *ranks, int capacity)
{
	int	i;

	context->a.depth = capacity;
	i = 0;
	while (i < capacity)
	{
		add_node(&context->a.top, out_values[i], ranks[i]);
		i++;
	}
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

static int	*compute_ranks(const int *values, int size)
{
	int	i;
	int	j;
	int *ranks;
	
	ranks = xalloc(size, sizeof(int));
	if (!ranks)
		put_error_n_exit();
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
	int *ranks;

	if (!validate_no_dups(out_values, size))
		return ;
	ranks = compute_ranks(out_values, size);
	stacks_init(context, out_values, ranks, size);
	free(ranks);
}
