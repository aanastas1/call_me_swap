/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:15:47 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 12:01:33 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	context_init(t_context *context)
{
	ft_memset(context, 0, sizeof(*context));
	context->strategy = NONE;
	context->bench_enabled = 0;
}

static void	free_all(t_context *context)
{
	if (!context)
		return ;
	free_stack(&context->a);
	free_stack(&context->b);
	ft_memset(context, 0, sizeof(*context));
}

void	strategy_selector(t_context *context)
{
	if (context->strategy == NONE)
		strategy_adaptive(context);
	if (context->strategy == SIMPLE)
		strategy_simple(context);
	if (context->strategy == MEDIUM)
		strategy_medium(context);
	if (context->strategy == COMPLEX)
		strategy_complex(context);
	if (context->strategy == ADAPTIVE)
		strategy_adaptive(context);
}

void	strategy_adaptive(t_context *context)
{
	if (context->a.depth <= 50)
		strategy_simple(context);
	if (context->disorder < 0.05)
		strategy_simple(context);
	else if (context->disorder < 0.35)
		strategy_medium(context);
	else
		strategy_complex(context);
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (1);
	context_init(&context);
	parse_args(argc, argv, &context);
	if (context.a.depth == 0)
	{
		free_all(&context);
		put_error_n_exit();
	}
	strategy_selector(&context);
	if (context.bench_enabled)
		bench_print_and_counts(&context);
	free_all(&context);
	return (0);
}
