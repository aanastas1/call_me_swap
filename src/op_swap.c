/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 21:08:05 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void swap_top(t_stack *stack)
{
    t_node *a;
    t_node *b;
    t_node *a_prev;
    t_node *b_next;

    if (!stack || stack->depth <= 1)
        return;

    a = stack->top;      // first/top
    b = a->next;        // second

    a_prev = a->prev;   // node before a
    b_next = b->next;   // node after b

    // Re-link a and b swapped: b becomes new top
    a_prev->next = b;
    b->prev = a_prev;

    b->next = a;
    a->prev = b;

    a->next = b_next;
    b_next->prev = a;

    stack->top = b;
}

/*
static void swap_top(t_stack *stack)
{
    t_node	*top;
	t_node	*prev;
	t_node	*prev_prev;
	t_node	*top_next;

	top = stack->top;
	prev = top->prev;
	prev_prev = prev->prev;
	top_next = top->next;
	stack->top = prev;
	prev->next = top;
	prev->prev = prev_prev;
	top->prev = prev;
	top->next = top_next;
	prev_prev->next = prev;
	top_next->prev = top;
}
	*/

void	sa(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	swap_top(&context->a);
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	swap_top(&context->b);
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		swap_top(&context->a);
	if (context->b.depth > 1)
		swap_top(&context->b);
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

