/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:19:27 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/19 18:02:58 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void blocksort(t_context *context)
{
    int i;

    i = context->a.depth - 1;
    while (i >= 1)
    {
        if (context->a.elements[i].rank <  context->a.elements[i - 1].rank)
        {
            pb(context);
            pb(context);
        }
        else
        {
            sa(context);
            pb(context);
            pb(context);
        }
        i -=2;
    }
    if (context->a.depth % 2 != 0)
        pb(context);  
}

void blocksort1(t_context *context)
{
    int i;

    i = context->b.depth - 1;
    while (i >= 1)
    {
        if (context->b.elements[i].rank <  context->b.elements[i - 1].rank)
        {
            pa(context);
            pa(context);
        }
        else
        {
            sb(context);
            pa(context);
            pa(context);
        }
        i -=2;
    }
    if (context->b.depth % 2 != 0)
        pa(context);  
}

