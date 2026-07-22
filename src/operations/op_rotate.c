/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 11:36:15 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_arr *stack)
{
	t_element	top;
	int			index;

	if (stack->depth < 2)
		return (0);
	top = stack->elements[0];
	index = 0;
	while (index < stack->depth - 1)
	{
		stack->elements[index] = stack->elements[index + 1];
		index++;
	}
	stack->elements[stack->depth - 1] = top;
	return (1);
}

void	ra(t_context *context)
{
	if (!rotate_stack(&context->a))
		return ;
	context->op_counts[RA]++;
	context->op_total++;
	write(1, "ra\n", 3);
}

void	rb(t_context *context)
{
	if (!rotate_stack(&context->b))
		return ;
	context->op_counts[RB]++;
	context->op_total++;
	write(1, "rb\n", 3);
}

void	rr(t_context *context)
{
	int	changed_a;
	int	changed_b;

	changed_a = rotate_stack(&context->a);
	changed_b = rotate_stack(&context->b);
	if (!changed_a && !changed_b)
		return ;
	context->op_counts[RR]++;
	context->op_total++;
	write(1, "rr\n", 3);
}
