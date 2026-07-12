/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/12 19:22:19 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_init(t_arr *arr, int capacity)
{
	arr->num = malloc(capacity * sizeof(int));
	if (!arr->num)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	arr->start = 0;
	arr->len = 0;
	arr->size = capacity;
}

void context_init(t_context *context, int capacity)
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
    /* или цикл: for (int i = 0; i < COUNT; i++) context->op_counts[i] = 0; */
}

int main(int argc, char **argv)
{
	int		*values;
	int		n;
	double	disorder;
	int		*ranks;
	t_context	context;

	if (argc < 2)
		return (0);
	context_init(&context, argc);
	values = NULL;
	n = parse_args(argc, argv, &values, &context);
	if (n <= 0 || !values)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

	if (!validate_ints_and_no_dups(values, n))
		return (0);

	disorder = compute_disorder_values(values, n);
	ranks = compute_ranks(values, n);

	/* дальше: build stacks a/b, стратегия, операции */
	(void)disorder;
	(void)ranks;

	free(values);
	free(ranks);
	return (0);
}

