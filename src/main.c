/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:31:31 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:37 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Parses, validates, ranks, allocates, and fills the initial stack. */
static int	prepare_context(t_context *context, int argc, char **argv)
{
	int	*values;
	int	*ranks;
	int	count;

	values = NULL;
	ranks = NULL;
	count = parse_args(argc, argv, &values, context);
	if (count < 1 || !validate_no_dups(values, count))
	{
		free(values);
		return (0);
	}
	ranks = compute_ranks(values, count);
	if (!ranks || !init_context(context, count))
	{
		free(values);
		free(ranks);
		free_context(context);
		return (0);
	}
	context->disorder = compute_disorder_values(values, count);
	setup_stacks(context, values, ranks, count);
	free(values);
	free(ranks);
	return (1);
}

/* Starts the forced strategy or the adaptive default strategy. */
static void	run_strategy(t_context *context)
{
	if (context->strategy == SIMPLE)
		strategy_simple(context);
	else if (context->strategy == MEDIUM)
		strategy_medium(context);
	else if (context->strategy == COMPLEX)
		strategy_complex(context);
	else
		strategy_adaptive(context);
}

/* Parses input, prepares ranked stacks, sorts, reports, and cleans up. */
int	main(int argc, char **argv)
{
	t_context	context;

	if (argc == 1)
		return (0);
	context = (t_context){0};
	context.strategy = NONE;
	if (!prepare_context(&context, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	run_strategy(&context);
	if (context.bench_enabled)
		bench_print_and_counts(&context);
	free_context(&context);
	return (0);
}
