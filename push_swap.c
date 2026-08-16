/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:15:47 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/15 18:38:04 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	context_init(t_context *context)
{
	*context = (t_context){
		.a = (t_stack){ .top = NULL, .depth = 0 },
		.b = (t_stack){ .top = NULL, .depth = 0 },
		.disorder = -1.0,
		.strategy = NONE,
		.bench_enabled = 0,
		.op_total = 0,
		.op_counts = (int [COUNT]){0},
		.strategy_name = NULL,
		.complexity = NULL,
	};
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
	{
		context->strategy_name = "Simple";
		context->complexity = "O(n^2)";
		strategy_simple(context);
	}
	if (context->strategy == MEDIUM)
	{
		context->strategy_name = "Medium";
		context->complexity = "O(n√n))";
		strategy_medium(context);
	}
	if (context->strategy == COMPLEX)
	{
		context->strategy_name = "Complex";
		context->complexity = "O(nlog(n))";
		strategy_complex(context);
	}
	if (context->strategy == ADAPTIVE)
		strategy_adaptive(context);
}

void	strategy_adaptive(t_context *context)
{
	context->strategy_name = "Adaptive";
	if (context->a.depth <= 20)
	{
		context->complexity = "O(n^2)";
		strategy_simple(context);
	}
	else if (context->disorder < 0.05)
	{
		context->complexity = "O(n^2)";
		strategy_simple(context);
	}
	else if (context->disorder < 0.35)
	{
		context->complexity = "O(n√n))";
		strategy_medium(context);
	}
	else
	{
		context->complexity = "O(nlog(n))";
		strategy_complex(context);
	}
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (0);
	context_init(&context);
	parse_args(argc, argv, &context);
	if (!context.disorder && !context.bench_enabled)
		return (free_all(&context), 0);
	else if (!context.disorder && context.bench_enabled)
		return (bench_print_and_counts(&context), free_all(&context), 0);
	if (context.a.depth == 0)
		return (free_all(&context), put_error(), 1);
	strategy_selector(&context);
	if (context.bench_enabled)
		bench_print_and_counts(&context);
	return (free_all(&context), 0);
}
