/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 17:06:54 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void swap(t_arr *arr, int logical_idx1, int logical_idx2)
{
	t_element tmp;
	int idx1;
	int idx2;

	idx1 = phys_idx(arr, logical_idx1);
	idx2 = phys_idx(arr, logical_idx2);

	tmp = arr->elements[idx1];
	arr->elements[idx1] = arr->elements[idx2];
	arr->elements[idx2] = tmp;
}

void	rra(t_context *context)
{
	if (context->a.depth <= 1)
		return ;
	context->a.bottom = phys_idx(&context->a, context->a.depth - 1);
	context->op_counts[RRA]++;
	context->op_total++;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_context *context)
{
	if (context->b.depth <= 1)
		return ;
	context->b.bottom = phys_idx(&context->b, context->b.depth - 1);
	context->op_counts[RRB]++;
	context->op_total++;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.bottom = phys_idx(&context->a, context->a.depth - 1);
	if (context->b.depth > 1)
		context->b.bottom = phys_idx(&context->b, context->b.depth - 1);
	context->op_counts[RRR]++;
	context->op_total++;
	ft_putstr_fd("rrr\n", 1);
}
