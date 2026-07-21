/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/20 20:18:26 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_it_b(t_context *context, int idx)
{
    if (idx < context->a.depth / 2)
    {
        while (idx--)
            ra(context);
        pb(context);
        print_stack_a_b(context);
    }
    else
    {
        idx = context->a.depth - idx;
        while (idx--)
            rra(context);
        pb(context);
        print_stack_a_b(context);
    }
}

void sort_stacks(t_context *context)
{
    int delimiter;
    int i;
    int pass_nbr;
   /* int capacity;

    capacity = context->a.depth;*/
    if (context->a.depth <= 5)
        return;
    delimiter = context->a.depth / 2;
    pass_nbr = context->a.depth / 2;
    i = 0;
    while (pass_nbr && i < context->a.depth - 1)
    {
        if (context->a.elements[i].rank < delimiter)
        {
            push_it_b(context, i);
            pass_nbr--;
            i = -1;
        }
        i++;
    }
    sort_stacks(context);
}