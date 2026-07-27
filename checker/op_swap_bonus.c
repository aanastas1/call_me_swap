/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/27 19:35:29 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void swap_top(t_stack *stack)
{
    t_node *a;
    t_node *b;
    t_node *prev;
    t_node *next;

    if (!stack || stack->depth <= 1)
        return;
    a = stack->top;
    b = a->next;
    if (stack->depth == 2)
    {
        stack->top = b;
        return;
    }
    prev = a->prev;
    next = b->next;
    prev->next = b;
    b->prev = prev;
    b->next = a;
    a->prev = b;
    a->next = next;
    next->prev = a;
    stack->top = b;
}

void	sa(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	swap_top(&context->a);
}

void	sb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	swap_top(&context->b);
}

void	ss(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		swap_top(&context->a);
	if (context->b.depth > 1)
		swap_top(&context->b);
}

