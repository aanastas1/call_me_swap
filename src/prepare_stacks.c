/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/17 12:28:42 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*compute_ranks(const int *values, int n)
{
	int	*temp;
	int	i;
	int	j;

	temp = malloc(n * sizeof(int));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		j = 0;
		while (j < n)
		{
			if (values[j] < values[i])
				temp[i]++;
			j++;
		}
		i++;
	}
	return (temp);
}

void	setup_stacks(t_context *context, int *values, int *ranks, int n)
{
	int	i;

	printf("DEBUG: setup_stacks start\n");
	i = 0;
	while (i < n)
	{
		context->a.elements[i].value = values[i];
		context->a.elements[i].rank = ranks[i];
		i++;
	}
	context->a.depth = n;
}

void	swap(t_arr *arr, int logical_idx1, int logical_idx2)
{
	t_element	tmp;
	int			idx1;
	int			idx2;

	idx1 = phys_idx(arr, logical_idx1);
	idx2 = phys_idx(arr, logical_idx2);
	tmp = arr->elements[idx1];
	arr->elements[idx1] = arr->elements[idx2];
	arr->elements[idx2] = tmp;
}