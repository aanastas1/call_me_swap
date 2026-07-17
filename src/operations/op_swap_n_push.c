/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_n_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/14 20:02:43 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	sa(t_context *context)
{
	t_element	tmp;
	int			top;

	if (context->a.depth <= 1) /* Not enough elements to swap */
		return ;
	top = (context->a.bottom + context->a.depth - 1) % context->a.size;
	tmp = context->a.elements[top];
	context->a.elements[top] = context->a.elements[top - 1];
	context->a.elements[top - 1] = tmp;
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_context *context)
{
	t_element	tmp;
	int			top;

	if (context->b.depth <= 1)
		return ;
	top = (context->b.bottom + context->b.depth - 1) % context->b.size;
	tmp = context->b.elements[top];
	context->b.elements[top] = context->b.elements[top - 1];
	context->b.elements[top - 1] = tmp;
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_context *context)
{
	t_element	tmp;
	int			top_a;
	int			top_b;

	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
	{
		top_a = (context->a.bottom + context->a.depth - 1) % context->a.size;
		tmp = context->a.elements[top_a];
		context->a.elements[top_a] = context->a.elements[top_a - 1];
		context->a.elements[top_a - 1] = tmp;
	}
	if (context->b.depth > 1)
	{
		top_b = (context->b.bottom + context->b.depth - 1) % context->b.size;
		tmp = context->b.elements[top_b];
		context->b.elements[top_b] = context->b.elements[top_b - 1];
		context->b.elements[top_b - 1] = tmp;
	}
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_context *context)
{
	int	top_a;
	int	top_b;

	if (context->b.depth == 0)
		return ;
	context->a.depth++;
	top_b = (context->b.bottom + context->b.depth - 1) % context->b.size;
	top_a = (context->a.bottom + context->a.depth - 1) % context->a.size;
	context->a.elements[top_a] = context->b.elements[top_b];
	context->b.depth--;
	context->op_counts[PA]++;
	context->op_total++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_context *context)
{
	int	top_a;
	int	top_b;

	if (context->a.depth == 0)
		return ;
	context->b.depth++;
	top_a = (context->a.bottom + context->a.depth - 1) % context->a.size;
	top_b = (context->b.bottom + context->b.depth - 1) % context->b.size;
	context->b.elements[top_b] = context->a.elements[top_a];
	context->a.depth--;
	context->op_counts[PB]++;
	context->op_total++;
	ft_putstr_fd("pb\n", 1);
}
