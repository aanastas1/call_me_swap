/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 14:22:23 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void swap_top(t_element *elem)
{
	t_element tmp;

	tmp = elem[0];
	elem[0] = elem[1];
	elem[1] = tmp;
}

void	sa(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	swap_top(context->a.elements);
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	swap_top(context->b.elements);
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		swap_top(context->a.elements);
	if (context->b.depth > 1)
		swap_top(context->b.elements);
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

