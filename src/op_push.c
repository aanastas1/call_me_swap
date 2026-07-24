/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:50:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/24 21:29:43 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"


static void	push_node(t_stack *dest, t_stack *src)
{
	t_node	*node;
	t_node	*tail;

	// 1. Извлекаем узел
	node = src->top;
	src->top = src->top->next;

	// 2. Если src стал пустым
	if (src->top == node)
		src->top = NULL;
	else
	{
		// Замыкаем новый head с хвостом в src
		src->top->prev = node->prev;
		node->prev->next = src->top;
	}

	// 3. Вставляем в dest
	if (!dest->top)
	{
		dest->top = node;
		node->next = node;
		node->prev = node;
	}
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
	context->op_counts[PA]++;
	context->op_total++;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_context *context)
{
	if (context->a.depth == 0)
		return ;
	push_node(&context->b, &context->a);
	context->a.depth--;
	context->b.depth++;
	context->op_counts[PB]++;
	context->op_total++;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
