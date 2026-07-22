/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/20 18:26:32 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	ra(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->a.depth <= 1)
		return;
	tmp = context->a.elements[0];
	i = 0;
	while (i < context->a.depth - 1)
	{
		context->a.elements[i] = context->a.elements[i + 1];
		i++;
	}
	context->a.elements[context->a.depth - 1] = tmp;
	context->op_counts[RA]++;
	context->op_total++;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->b.depth <= 1)
		return;
	tmp = context->b.elements[0];
	i = 0;
	while (i < context->b.depth - 1)
	{
		context->b.elements[i] = context->b.elements[i + 1];
		i++;
	}
	context->b.elements[context->b.depth - 1] = tmp;
	context->op_counts[RB]++;
	context->op_total++;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rr(t_context *context)
{
	t_element	tmp;
	int	i;

	if (context->a.depth > 1)
	{
		tmp = context->a.elements[0];
		i = -1;
		while (++i < context->a.depth - 1)
			context->a.elements[i] = context->a.elements[i + 1];
		context->a.elements[context->a.depth - 1] = tmp;
	}
	if (context->b.depth > 1)
	{
		tmp = context->b.elements[0];
		i = -1;
		while (++i < context->b.depth - 1)
			context->b.elements[i] = context->b.elements[i + 1];
		context->b.elements[context->b.depth - 1] = tmp;
	}
	context->op_counts[RR]++;
	context->op_total++;
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
