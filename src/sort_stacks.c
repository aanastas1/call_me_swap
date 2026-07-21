/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/21 17:31:42 by aloiko           ###   ########.fr       */
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
    }
    else
    {
        idx = context->a.depth - idx;
        while (idx--)
            rra(context);
        pb(context);
    }
}
void push_it_a(t_context *context, int idx)
{
    if (idx < context->b.depth / 2)
    {
        while (idx--)
            rb(context);
        pa(context);
    }
    else
    {
        idx = context->b.depth - idx;
        while (idx--)
            rrb(context);
        pa(context);
    }
}

void sort_stacks(t_context *context, int offset)
{
    int delimiter;
    int i;
    int pass_nbr;
    int new_offset;
   /* int capacity;

    capacity = context->a.depth;*/
    if (context->a.depth <= 5)
        return ;
    
    new_offset = offset + (context->a.depth / 2);
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
    delimiter = context->b.depth / 2;
    pass_nbr = context->b.depth / 2;
    i = 0;
    while (pass_nbr && i < context->a.depth - 1)
    {
        if (context->b.elements[i].rank < delimiter)
        {
            push_it_a(context, i);
            pass_nbr--;
            i = -1;

        }
        i++;
    }
    sort_stacks(context, new_offset);
}


void strategy_medium(t_context *context)
{
    sort_stacks(context, 0);
}