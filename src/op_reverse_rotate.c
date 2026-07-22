/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 13:38:00 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void rotate_down(t_arr *arr)
{
    t_element tmp;
    int i;

    tmp = arr->elements[arr->depth - 1];
    i = arr->depth;
    while (--i > 0)
        arr->elements[i] = arr->elements[i - 1];
    arr->elements[0] = tmp;
}

void	rra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	rotate_down(&(context->a));
	context->op_counts[RRA]++;
	context->op_total++;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_context *context)
{
	if (context->b.depth <= 1)
		return ;
	rotate_down(&(context->b));
	context->op_counts[RRB]++;
	context->op_total++;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		rotate_down(&(context->a));
	if (context->b.depth > 1)
		rotate_down(&(context->b));
	context->op_counts[RRR]++;
	context->op_total++;
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
