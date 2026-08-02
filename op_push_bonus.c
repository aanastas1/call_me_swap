/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:50:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 15:37:04 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_node	*detach_top(t_stack *src)
{
	t_node	*node;
	t_node	*next;
	t_node	*prev;

	if (!src->top)
		return (NULL);
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
	return (node);
}

static void	attach_to_dest(t_stack *dest, t_node *node)
{
	t_node	*tail;

	if (!node)
		return ;
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

static void	push_node(t_stack *dest, t_stack *src)
{
	t_node	*node;

	node = detach_top(src);
	attach_to_dest(dest, node);
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
