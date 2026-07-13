/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/13 21:50:20 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  validate_no_dups(int *values, int n)
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

double compute_disorder_values(const int *values, int n)
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
		}
	}
	return ((double)mistakes / total_pairs);
}

int   *compute_ranks(const int *values, int n)
{
	int *temp;
	int i;
	int j;

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

void setup_stacks(t_context *context, int *values, int *ranks, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		context->a.elements[i].value = values[i];
		context->a.elements[i].rank = ranks[i];
		i++;
	}
	context->a.len = n;
}