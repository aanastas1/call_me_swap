/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 18:19:37 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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

static void sort_stacks(t_context *context, int offset)
{
    int delimiter;
    int i;
    int count;
    int size;
   
    if (context->a.depth <= 5)
    {
        size = context->a.depth;
        while (size--)
        {
            pa(context);
            print_stack_a_b(context);
        }
        return;
    }
    else
    {
        count = context->a.depth / 2;
        i = 0;
        while (count && context->a.depth)
        {
            if (context->a.elements[i].rank < offset)
            {
                push_it_b(context, i);
                count--;
                i = -1;
            }
            i++;
        }
        delimiter = offset + context->a.depth / 2;
        sort_stacks(context, delimiter);
        delimiter = offset - context->b.depth / 2;
        count = context->b.depth / 2;
        i = 0;
        while (count && i < context->b.depth)
        {
            if (context->b.elements[i].rank < delimiter)
            {
                push_it_a(context, i);
                count--;
                i = -1;
            }
            i++;
        }
        sort_stacks(context, delimiter);
    }
   // merge_a_b();
}

void strategy_medium(t_context *context)
{
    int delimiter;

    delimiter = context->a.depth / 2;
    sort_stacks(context, delimiter);
}*/