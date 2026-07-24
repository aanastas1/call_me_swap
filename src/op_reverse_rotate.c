/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/24 19:38:57 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	rra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	context->a.top = context->a.top->prev;
	context->op_counts[RRA]++;
	context->op_total++;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_context *context)
{
	if (context->b.depth <= 1)
		return ;
	context->b.top = context->b.top->prev;
	context->op_counts[RRB]++;
	context->op_total++;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.top = context->a.top->prev;
	if (context->b.depth > 1)
		context->b.top = context->b.top->prev;
	context->op_counts[RRR]++;
	context->op_total++;
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
