/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 13:38:32 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void rotate_up(t_arr *arr)
{
    t_element tmp;
    int i;

    tmp = arr->elements[0];
    i = -1;
    while (++i < arr->depth - 1)
        arr->elements[i] = arr->elements[i + 1];
    arr->elements[arr->depth - 1] = tmp;
}

void	ra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	rotate_up(&(context->a));
	context->op_counts[RA]++;
	context->op_total++;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	rotate_up(&(context->b));
	context->op_counts[RB]++;
	context->op_total++;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		rotate_up(&(context->a));
	if (context->b.depth > 1)
		rotate_up(&(context->b));
	context->op_counts[RR]++;
	context->op_total++;
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
