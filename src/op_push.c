/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:50:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 14:18:03 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void push_top(t_arr *src, t_arr *dst)
{
    int i;

    i = dst->depth;
    while (--i >= 0)
        dst->elements[i + 1] = dst->elements[i];
    dst->elements[0] = src->elements[0];
    i = -1;
    while (++i < src->depth - 1)
        src->elements[i] = src->elements[i + 1];
    dst->depth++;
    src->depth--;
}

void	pa(t_context *context)
{
	if (context->b.depth == 0)
		return;
	push_top(&context->b, &context->a);
	context->op_counts[PA]++;
	context->op_total++;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_context *context)
{
	if (context->a.depth == 0)
		return;
	push_top(&context->a, &context->b);
	context->op_counts[PB]++;
	context->op_total++;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
