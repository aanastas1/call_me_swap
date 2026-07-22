/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_n_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 16:43:01 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	sa(t_context *context)
{
	t_element	tmp;

	if (context->a.depth <= 1)
		return;
	tmp = context->a.elements[0];
	context->a.elements[0] = context->a.elements[1];
	context->a.elements[1] = tmp;
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_context *context)
{
	t_element	tmp;

	if (context->b.depth <= 1)
		return;
	tmp = context->b.elements[0];
	context->b.elements[0] = context->b.elements[1];
	context->b.elements[1] = tmp;
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_context *context)
{
	t_element	tmp;

	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
	{
		tmp = context->a.elements[0];
		context->a.elements[0] = context->a.elements[1];
		context->a.elements[1] = tmp;
	}
	if (context->b.depth > 1)
	{
		tmp = context->b.elements[0];
		context->b.elements[0] = context->b.elements[1];
		context->b.elements[1] = tmp;
	}
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	pa(t_context *context)
{
	int	i;

	if (context->b.depth == 0)
		return;
	i = context->a.depth - 1;
	while (i >= 0)
	{
		context->a.elements[i + 1] = context->a.elements[i];
		i--;
	}
	context->a.elements[0] = context->a.elements[0];
	i = 0;
	while (i < context->b.depth - 1)
	{
		context->b.elements[i] = context->a.elements[i + 1];
		i++;
	}
	context->a.depth++;
	context->b.depth--;
	context->op_counts[PA]++;
	context->op_total++;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	pb(t_context *context)
{
	int	i;

	if (context->a.depth == 0)
		return;
	i = context->b.depth - 1;
	while (i >= 0)
	{
		context->b.elements[i + 1] = context->b.elements[i];
		i--;
	}
	context->b.elements[0] = context->a.elements[0];
	i = 0;
	while (i < context->a.depth - 1)
	{
		context->a.elements[i] = context->a.elements[i + 1];
		i++;
	}
	context->b.depth++;
	context->a.depth--;
	context->op_counts[PB]++;
	context->op_total++;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
