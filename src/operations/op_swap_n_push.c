/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_n_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 11:36:16 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_arr *stack)
{
	t_element	temporary;

	if (stack->depth < 2)
		return (0);
	temporary = stack->elements[0];
	stack->elements[0] = stack->elements[1];
	stack->elements[1] = temporary;
	return (1);
}

void	sa(t_context *context)
{
	if (!swap_stack(&context->a))
		return ;
	context->op_counts[SA]++;
	context->op_total++;
	write(1, "sa\n", 3);
}

void	sb(t_context *context)
{
	if (!swap_stack(&context->b))
		return ;
	context->op_counts[SB]++;
	context->op_total++;
	write(1, "sb\n", 3);
}

void	ss(t_context *context)
{
	int	changed_a;
	int	changed_b;

	changed_a = swap_stack(&context->a);
	changed_b = swap_stack(&context->b);
	if (!changed_a && !changed_b)
		return ;
	context->op_counts[SS]++;
	context->op_total++;
	write(1, "ss\n", 3);
}
