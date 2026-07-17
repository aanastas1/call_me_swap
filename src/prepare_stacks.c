/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/18 00:38:54 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    //context->strategy = NONE;

    // 3. Инициализация флагов и счетчиков
    context->bench_enabled = 0;
    context->op_total = 0;
    
    // Обнуляем массив счетчиков операций
    ft_bzero(context->op_counts, sizeof(context->op_counts)); 
   
}

int	validate_no_dups(int *values, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (values[i] == values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

double	compute_disorder_values(const int *values, int n)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total_pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}

void	compute_ranks(t_context *context, const int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		context->a.elements[i].rank = 0;
		j = 0;
		while (j < size)
		{
			if (values[j] < values[i])
				context->a.elements[i].rank++;
			j++;
		}
		i++;
	}
}

void	setup_stacks(t_context *context, int *values, int size)
{
	int	i;

	printf("DEBUG: setup_stacks start\n");
	context_init(context, size);
	compute_ranks(context, values, size);

	i = 0;
	while (i < size)
	{
		context->a.elements[i].value = values[i];
		i++;
	}
	context->a.depth = size;
}
