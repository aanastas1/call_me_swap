/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:50:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/26 19:34:30 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void push_node(t_stack *dest, t_stack *src)
{
    t_node *node;
    t_node *next;
    t_node *prev;
    t_node *tail;

    if (!src->top)
        return;

    node = src->top;

    /* remove from src */
    if (src->depth == 1)
    {
        src->top = NULL;
    }
    else
    {
        next = node->next;
        prev = node->prev;

        next->prev = prev;
        prev->next = next;

        src->top = next;
    }

    /* detach node */
    node->next = node;
    node->prev = node;

    /* insert into dest */
    if (!dest->top)
    {
        dest->top = node;
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
	printf("AFTER pa\n");
	check_circle(&context->a, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
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
	printf("AFTER pb\n");
	check_circle(&context->b, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
}
