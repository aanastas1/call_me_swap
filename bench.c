/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:44:23 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 19:19:41 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_count(const char *name, int count)
{
	bench_putstr(name);
	bench_putnbr(count);
}

/* Prints swap and push operation counters on one benchmark line. */
static void	print_swap_push_counts(t_context *context)
{
	bench_putstr("[bench] ");
	print_count("sa: ", context->op_counts[SA]);
	print_count(" sb: ", context->op_counts[SB]);
	print_count(" ss: ", context->op_counts[SS]);
	print_count(" pa: ", context->op_counts[PA]);
	print_count(" pb: ", context->op_counts[PB]);
	bench_putstr("\n");
}

/* Prints rotate operation counters on one benchmark line. */
static void	print_rotate_counts(t_context *context)
{
	bench_putstr("[bench] ");
	print_count("ra: ", context->op_counts[RA]);
	print_count(" rb: ", context->op_counts[RB]);
	print_count(" rr: ", context->op_counts[RR]);
	print_count(" rra: ", context->op_counts[RRA]);
	print_count(" rrb: ", context->op_counts[RRB]);
	print_count(" rrr: ", context->op_counts[RRR]);
	bench_putstr("\n");
}

/* Prints all required metrics to stderr after sorting is complete. */
void	bench_print_and_counts(t_context *context)
{
	if (!context->bench_enabled)
		return ;
	bench_putstr("[bench] disorder: ");
	bench_put_percent(context->disorder);
	bench_putstr("[bench] strategy: ");
	bench_putstr(context->strategy_name);
	bench_putstr(" / ");
	bench_putstr(context->complexity);
	bench_putstr("\n[bench] total_ops: ");
	bench_putnbr(context->op_total);
	bench_putstr("\n");
	print_swap_push_counts(context);
	print_rotate_counts(context);
}
