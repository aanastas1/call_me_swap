/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:36 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Allocates one empty stack with room for every input value. */
static int	init_stack(t_arr *stack, int capacity)
{
	stack->elements = malloc(sizeof(t_element) * capacity);
	if (!stack->elements)
		return (0);
	stack->depth = 0;
	stack->capacity = capacity;
	return (1);
}

/* Allocates both stacks used by the sorting operations. */
int	init_context(t_context *context, int capacity)
{
	if (!init_stack(&context->a, capacity))
		return (0);
	if (!init_stack(&context->b, capacity))
	{
		free(context->a.elements);
		context->a.elements = NULL;
		return (0);
	}
	return (1);
}

/* Releases the two arrays owned by the stack context. */
void	free_context(t_context *context)
{
	free(context->a.elements);
	free(context->b.elements);
}
