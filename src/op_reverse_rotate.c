/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/14 20:43:03 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	rra(t_context *context)
{
	context->a.bottom = (context->a.bottom - 1 + context->a.size)
		% context->a.size;
	context->op_counts[RRA]++;
	context->op_total++;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_context *context)
{
	context->b.bottom = (context->b.bottom - 1 + context->b.size)
		% context->b.size;
	context->op_counts[RRB]++;
	context->op_total++;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_context *context)
{
	context->a.bottom = (context->a.bottom - 1 + context->a.size)
		% context->a.size;
	context->b.bottom = (context->b.bottom - 1 + context->b.size)
		% context->b.size;
	context->op_counts[RRR]++;
	context->op_total++;
	ft_putstr_fd("rrr\n", 1);
}
