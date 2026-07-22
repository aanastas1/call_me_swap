/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 11:36:13 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_arr *stack)
{
	t_element	bottom;
	int			index;

	if (stack->depth < 2)
		return (0);
	bottom = stack->elements[stack->depth - 1];
	index = stack->depth - 1;
	while (index > 0)
	{
		stack->elements[index] = stack->elements[index - 1];
		index--;
	}
	stack->elements[0] = bottom;
	return (1);
}

void	rra(t_context *context)
{
	if (!reverse_rotate_stack(&context->a))
		return ;
	context->op_counts[RRA]++;
	context->op_total++;
	write(1, "rra\n", 4);
}

void	rrb(t_context *context)
{
	if (!reverse_rotate_stack(&context->b))
		return ;
	context->op_counts[RRB]++;
	context->op_total++;
	write(1, "rrb\n", 4);
}

void	rrr(t_context *context)
{
	int	changed_a;
	int	changed_b;

	changed_a = reverse_rotate_stack(&context->a);
	changed_b = reverse_rotate_stack(&context->b);
	if (!changed_a && !changed_b)
		return ;
	context->op_counts[RRR]++;
	context->op_total++;
	write(1, "rrr\n", 4);
}
