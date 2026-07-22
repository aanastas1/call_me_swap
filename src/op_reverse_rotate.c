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

void	rra(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->a.depth <= 1)
		return;
	tmp = context->a.elements[context->a.depth - 1];
	i = context->a.depth - 1;
	while (i > 0)
	{
		context->a.elements[i] = context->a.elements[i - 1];
		i--;
	}
	context->a.elements[0] = tmp;
	context->op_counts[RRA]++;
	context->op_total++;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->b.depth <= 1)
		return ;
	tmp = context->b.elements[context->b.depth - 1];
	i = context->b.depth - 1;
	while (i > 0)
	{
		context->b.elements[i] = context->b.elements[i - 1];
		i--;
	}
	context->b.elements[0] = tmp;
	context->op_counts[RRB]++;
	context->op_total++;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->a.depth > 1)
	{
		tmp = context->a.elements[context->a.depth - 1];
		i = context->a.depth - 1;
		while (i > 0)
		{
			context->a.elements[i] = context->a.elements[i - 1];
			i--;
		}
		context->a.elements[0] = tmp;
	}
	if (context->b.depth > 1)
	{
		tmp = context->b.elements[context->b.depth - 1];
		i = context->b.depth - 1;
		while (i > 0)
		{
			context->b.elements[i] = context->b.elements[i - 1];
			i--;
		}
		context->b.elements[0] = tmp;
	}
	context->op_counts[RRR]++;
	context->op_total++;
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
