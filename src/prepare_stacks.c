/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 11:36:38 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rejects an input when two parsed values are equal. */
int	validate_no_dups(int *values, int count)
{
	int	first;
	int	second;

	first = 0;
	while (first < count - 1)
	{
		second = first + 1;
		while (second < count)
		{
			if (values[first] == values[second])
				return (0);
			second++;
		}
		first++;
	}
	return (1);
}

/* Measures the fraction of inverted input pairs before any operation. */
double	compute_disorder_values(const int *values, int count)
{
	long	mistakes;
	long	total_pairs;
	int		first;
	int		second;

	if (count < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	first = 0;
	while (first < count - 1)
	{
		second = first + 1;
		while (second < count)
		{
			total_pairs++;
			if (values[first] > values[second])
				mistakes++;
			second++;
		}
		first++;
	}
	return ((double)mistakes / total_pairs);
}

/* Maps each value to its sorted position from zero to count minus one. */
int	*compute_ranks(const int *values, int count)
{
	int	*ranks;
	int	value_index;
	int	other_index;

	ranks = malloc(sizeof(int) * count);
	if (!ranks)
		return (NULL);
	value_index = 0;
	while (value_index < count)
	{
		ranks[value_index] = 0;
		other_index = 0;
		while (other_index < count)
		{
			if (values[other_index] < values[value_index])
				ranks[value_index]++;
			other_index++;
		}
		value_index++;
	}
	return (ranks);
}

/* Copies input order into A so the first input value becomes the top. */
void	setup_stacks(t_context *context, const int *values,
		const int *ranks, int count)
{
	int	input_index;

	input_index = 0;
	while (input_index < count)
	{
		context->a.elements[input_index].value = values[input_index];
		context->a.elements[input_index].rank = ranks[input_index];
		input_index++;
	}
	context->a.depth = count;
}

/* Exchanges two elements addressed by logical stack indexes. */
void	swap(t_arr *stack, int first_index, int second_index)
{
	t_element	temporary;

	temporary = stack->elements[first_index];
	stack->elements[first_index] = stack->elements[second_index];
	stack->elements[second_index] = temporary;
}
