/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/13 21:50:18 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
static void stack_init(t_arr *arr, int capacity)
{
	arr->elements = malloc(capacity * sizeof(t_element));
	if (!arr->elements)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	arr->start = 0;
	arr->len = 0;
	arr->size = capacity;
}

static void context_init(t_context *context, int capacity)
{
    // 1. Инициализация стеков (массивов)
    // Выделяем память под arr, задаем capacity, обнуляем size и start
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
static void put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	
}

static void free_all(t_context *context, int *values, int *ranks)
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

void print_stack_a(t_context *context)
{
	int i;
	ft_putstr_fd("Stack A: (Value | Rank): [ ", 1);
	i = 0;
	while (i < context->a.len)
	{
		ft_putnbr_fd(context->a.elements[context->a.start + i].value, 1);
		ft_putstr_fd(" | ", 1);
		ft_putnbr_fd(context->a.elements[context->a.start + i].rank, 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("]\n", 1);
}
#include <stdio.h>

int main(int argc, char **argv)
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
	context_init(&context, argc);
	n = parse_args(argc, argv, &values, &context);
	if (n <= 0 || !values) 
	{
		put_error();
		free_all(&context, values, ranks);
		return (0);
	}
	if (!validate_no_dups(values, n))
		return (0);
	ranks = compute_ranks(values, n);
	if (!ranks)
	{
		put_error();
		free_all(&context, values, ranks);
		return (0);
	}
	setup_stacks(&context, values, ranks, n);
	disorder = compute_disorder_values(values, n);
	
	printf("Disorder: %.2f\n", disorder);
	printf("DEBUG: n = %d\n", n);
	printf("DEBUG: values = %d\n", *values);
	printf("DEBUG: len = %d, size = %d\n", context.a.len, context.a.size);
	print_stack_a(&context);

	free_all(&context, values, ranks);
	return (0);
}

