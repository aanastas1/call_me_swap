/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/26 19:34:44 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

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
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	printf("AFTER sa\n");
	check_circle(&context->a, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
}

void	sb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	swap_top(&context->b);
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	printf("AFTER sb\n");
	check_circle(&context->b, "B");
	check_circle(&context->b, "B");
}

void	ss(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		swap_top(&context->a);
	if (context->b.depth > 1)
		swap_top(&context->b);
	printf("AFTER ss\n");
	check_circle(&context->b, "B");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

