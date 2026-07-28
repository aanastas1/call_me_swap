/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 18:36:08 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	context->a.top = context->a.top->next;
}

void	rb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	context->b.top = context->b.top->next;
}

void	rr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.top = context->a.top->next;
	if (context->b.depth > 1)
		context->b.top = context->b.top->next;
}
