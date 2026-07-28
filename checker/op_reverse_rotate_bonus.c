/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:21:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 18:36:01 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	context->a.top = context->a.top->prev;
}

void	rrb(t_context *context)
{
	if (context->b.depth <= 1)
		return ;
	context->b.top = context->b.top->prev;
}

void	rrr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.top = context->a.top->prev;
	if (context->b.depth > 1)
		context->b.top = context->b.top->prev;
}
