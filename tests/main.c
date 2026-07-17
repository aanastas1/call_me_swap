/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:31:31 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/17 12:31:32 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_context(t_context *context, int capacity)
{
	context->a.elements = malloc(sizeof(t_element) * capacity);
	context->b.elements = malloc(sizeof(t_element) * capacity);
	if (!context->a.elements || !context->b.elements)
	{
		free(context->a.elements);
		free(context->b.elements);
		return (0);
	}
	context->a = (t_arr){context->a.elements, 0, 0, capacity};
	context->b = (t_arr){context->b.elements, 0, 0, capacity};
	return (1);
}

static int	fail(t_context *context, int *values, int *ranks)
{
	free(values);
	free(ranks);
	free(context->a.elements);
	free(context->b.elements);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			*values;
	int			*ranks;
	int			count;
	double		disorder;

	if (argc == 1)
		return (0);
	context = (t_context){0};
	context.strategy = NONE;
	values = NULL;
	ranks = NULL;
	count = parse_args(argc, argv, &values, &context);
	if (count < 1 || !validate_no_dups(values, count))
		return (fail(&context, values, ranks));
	ranks = compute_ranks(values, count);
	if (!ranks || !init_context(&context, count))
		return (fail(&context, values, ranks));
	disorder = compute_disorder_values(values, count);
	setup_stacks(&context, values, ranks, count);
	if (count <= 5)
		sort_small(&context);
	if (context.bench_enabled)
		bench_print_and_counts(&context, disorder, "simple", "O(n^2)");
	free(values);
	free(ranks);
	free(context.a.elements);
	free(context.b.elements);
	return (0);
}
