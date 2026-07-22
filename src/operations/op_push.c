/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:26:52 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:11 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_stack(t_arr *destination, t_arr *source)
{
	int	index;

	if (source->depth == 0 || destination->depth >= destination->capacity)
		return (0);
	index = destination->depth;
	while (index > 0)
	{
		destination->elements[index] = destination->elements[index - 1];
		index--;
	}
	destination->elements[0] = source->elements[0];
	index = 0;
	while (index < source->depth - 1)
	{
		source->elements[index] = source->elements[index + 1];
		index++;
	}
	destination->depth++;
	source->depth--;
	return (1);
}

void	pa(t_context *context)
{
	if (!push_stack(&context->a, &context->b))
		return ;
	context->op_counts[PA]++;
	context->op_total++;
	write(1, "pa\n", 3);
}

void	pb(t_context *context)
{
	if (!push_stack(&context->b, &context->a))
		return ;
	context->op_counts[PB]++;
	context->op_total++;
	write(1, "pb\n", 3);
}
