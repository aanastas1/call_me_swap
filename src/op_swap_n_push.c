/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_n_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/13 21:50:21 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_context *context)
{
    t_element	tmp;

    if (context->a.len < 2)
        return ; /* Not enough elements to swap */
    tmp = context->a.elements[context->a.start];
    context->a.elements[context->a.start] = context->a.elements[context->a.start + 1];
    context->a.elements[context->a.start + 1] = tmp;
    context->op_counts[SA]++;
    context->op_total++;
    ft_putstr_fd("sa\n", 1);
}

void	sb(t_context *context)
{
	t_element	tmp;

	if (context->b.len < 2)
		return ;
	tmp = context->b.elements[context->b.start];
	context->b.elements[context->b.start] = context->b.elements[context->b.start+1];
	context->b.elements[context->b.start + 1] = tmp;
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_context *context)
{
	t_element	tmp;

    if (context->a.len < 2 && context->b.len < 2)
        return ; 
    if (context->a.len >= 2)
	{
		tmp = context->a.elements[context->a.start];
		context->a.elements[context->a.start] = context->a.elements[context->a.start + 1];
		context->a.elements[context->a.start + 1] = tmp;
	}
	if (context->b.len >=  2)
	{
		tmp = context->b.elements[context->b.start];
		context->b.elements[context->b.start] = context->b.elements[context->b.start+1];
		context->b.elements[context->b.start + 1] = tmp;
	}
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_context *context)
{
	if (context->b.len == 0)
		return ;
	
