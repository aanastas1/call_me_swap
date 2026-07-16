/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 17:12:05 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"


int phys_idx(t_arr *arr, int logical_idx)
{
	return (arr->bottom + logical_idx) % arr->depth;
}

void	ra(t_context *context)
{
	if (context->a.depth <= 1)
		return ;
	context->a.bottom = phys_idx(&context->a, 1);
	context->op_counts[RA]++;
	context->op_total++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_context *context)
{
	if (context->b.depth <= 1)
		return ;
	context->b.bottom = phys_idx(&context->b, 1);
	context->op_counts[RB]++;
	context->op_total++;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.bottom = phys_idx(&context->a, 1);
	if (context->b.depth > 1)
		context->b.bottom = phys_idx(&context->b, 1);
	context->op_counts[RR]++;
	context->op_total++;
	ft_putstr_fd("rr\n", 1);
}
