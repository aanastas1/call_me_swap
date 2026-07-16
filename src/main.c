/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 20:10:05 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

static void	stack_init(t_arr *arr, int capacity)
{
	arr->elements = malloc(capacity * sizeof(t_element));
	if (!arr->elements)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	arr->bottom = 0; /* Initialize bottom to 0 to indicate the stack is empty */
	arr->depth = 0;
	arr->size = capacity;
}

static void	context_init(t_context *context, int capacity)
{
    // 1. Инициализация стеков (массивов)
    // Выделяем память под arr, задаем capacity, обнуляем size и bottom
    stack_init(&context->a, capacity);
    stack_init(&context->b, capacity);

    // 2. Инициализация стратегии
    // Ставим дефолт (NONE), чтобы не зависеть от мусора в памяти
    context->strategy = NONE;

    // 3. Инициализация флагов и счетчиков
    context->bench_enabled = 0;
    context->op_total = 0;
    
    // Обнуляем массив счетчиков операций
    ft_bzero(context->op_counts, sizeof(context->op_counts)); 
   
}

static void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	
}

static void	free_all(t_context *context, int *values, int *ranks)
{
	if (values)
		free(values);
	if (ranks)
		free(ranks);
	if (context->a.elements)
		free(context->a.elements);
	if (context->b.elements)
		free(context->b.elements);
}

void print_stack_a_b(t_context *context)
{
	int	idx_a;
	int top_a;
	int idx_b;
	int top_b;

	top_a = context->a.depth - 1;
	top_b = context->b.depth - 1;
	ft_putstr_fd("Stack A: (Value | Rank): [ ", 1);
	ft_putstr_fd("                 Stack B: (Value | Rank): [\n", 1);
	while (top_a >= 0 || top_b >= 0)
	{
		if (top_a >= 0)
		{
			idx_a = phys_idx(&context->a, top_a);
			ft_putstr_fd("              ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].rank, 1);
			if (top_a == 0)
				ft_putstr_fd(" ]", 1);
			ft_putstr_fd("                       ", 1);
			top_a--;
		}
		if (top_b >= 0)
		{
			idx_b = phys_idx(&context->b, top_b);
			ft_putnbr_fd(context->b.elements[idx_b].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->b.elements[idx_b].rank, 1);
			if (top_b == 0)
				ft_putstr_fd(" ]", 1);
			top_b--;
		}
		ft_putstr_fd("             \n", 1);
		if (top_a < 0)
			ft_putstr_fd("                                            ", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	int		*values;
	int		n;
	double	disorder;
	int		*ranks;
	t_context	context;

	values = NULL;
	ranks = NULL;
	if (argc < 2)
		return (0);
	printf("DEBUG: main start\n");
	context_init(&context, argc);
	n = parse_args(argc, argv, &values, &context);
	printf("DEBUG: After parse_args\n");
	if (n <= 0 || !values) 
	{
		put_error();
		free_all(&context, values, ranks);
		return (0);
	}
	if (!validate_no_dups(values, n))
	{
		put_error();
		free_all(&context, values, ranks);
		return (0);
	}
	ranks = compute_ranks(values, n);
	if (!ranks)
	{
		put_error();
		free_all(&context, values, ranks);
		return (0);
	}
	setup_stacks(&context, values, ranks, n);
	printf("DEBUG: After setup_stacks\n");
	disorder = compute_disorder_values(values, n);
	print_stack_a_b(&context); /*print stack before small functions*/

	sa(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	ra(&context);
	ra(&context);
	rr(&context);
	rr(&context);
	rrr(&context);
	rb(&context);


	//turk_alg(&context);

	printf("Disorder: %.2f\n", disorder);
	printf("DEBUG: n = %d\n", n);
	printf("DEBUG: values = %d\n", *values);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	
	print_stack_a_b(&context); /* print stack after small functions */

	free_all(&context, values, ranks);
	return (0);
}

