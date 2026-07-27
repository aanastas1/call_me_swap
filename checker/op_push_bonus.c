/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:50:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/27 19:50:46 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void push_node(t_stack *dest, t_stack *src)
{
    t_node *node;
    t_node *next;
    t_node *prev;
    t_node *tail;

    node = src->top;
    if (src->depth == 1)
        src->top = NULL;
    else
    {
        next = node->next;
        prev = node->prev;
        next->prev = prev;
        prev->next = next;
        src->top = next;
    }
    node->next = node;
    node->prev = node;
    if (!dest->top)
        dest->top = node;
    else
    {
        tail = dest->top->prev;
        node->next = dest->top;
        node->prev = tail;
        tail->next = node;
        dest->top->prev = node;
        dest->top = node;
    }
}

void	pa(t_context *context)
{
	if (context->b.depth == 0)
		return ;
	push_node(&context->a, &context->b);
	context->a.depth++;
	context->b.depth--;
}

void	pb(t_context *context)
{
	if (context->a.depth == 0)
		return ;
	push_node(&context->b, &context->a);
	context->a.depth--;
	context->b.depth++;
}
