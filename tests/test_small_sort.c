/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:31:24 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/17 12:31:25 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_stats
{
	int	cases;
	int	max_operations;
}t_stats;

static int	init_context(t_context *context, int *order, int size)
{
	int	i;

	*context = (t_context){0};
	context->a.elements = malloc(sizeof(t_element) * size);
	context->b.elements = malloc(sizeof(t_element) * size);
	if (!context->a.elements || !context->b.elements)
		return (0);
	context->a = (t_arr){context->a.elements, 0, size, size};
	context->b = (t_arr){context->b.elements, 0, 0, size};
	i = 0;
	while (i < size)
	{
		context->a.elements[size - 1 - i].value = order[i];
		context->a.elements[size - 1 - i].rank = order[i];
		i++;
	}
	return (1);
}

static int	test_order(int *order, int size, t_stats *stats)
{
	t_context	context;

	if (!init_context(&context, order, size))
		return (0);
	sort_small(&context);
	if (!stack_is_sorted_asc(&context.a) || context.b.depth != 0)
	{
		fprintf(stderr, "failed permutation of size %d\n", size);
		free(context.a.elements);
		free(context.b.elements);
		return (0);
	}
	if (context.op_total > stats->max_operations)
		stats->max_operations = context.op_total;
	stats->cases++;
	free(context.a.elements);
	free(context.b.elements);
	return (1);
}

static int	generate(int *order, int *used, int index, int size,
		t_stats *stats)
{
	int	rank;

	if (index == size)
		return (test_order(order, size, stats));
	rank = 0;
	while (rank < size)
	{
		if (!used[rank])
		{
			used[rank] = 1;
			order[index] = rank;
			if (!generate(order, used, index + 1, size, stats))
				return (0);
			used[rank] = 0;
		}
		rank++;
	}
	return (1);
}

int	main(void)
{
	int		order[5];
	int		used[5];
	int		size;
	t_stats	stats;

	stats = (t_stats){0};
	size = 1;
	while (size <= 5)
	{
		used[0] = 0;
		used[1] = 0;
		used[2] = 0;
		used[3] = 0;
		used[4] = 0;
		if (!generate(order, used, 0, size, &stats))
			return (1);
		size++;
	}
	fprintf(stderr, "OK: %d permutations, max operations: %d\n",
		stats.cases, stats.max_operations);
	return (0);
}
