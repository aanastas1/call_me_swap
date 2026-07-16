/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:15:47 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 20:08:00 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_element(t_arr *arr, int nbr)
{
    int idx;
    int top;
    int delta;
    int res;
    int tmp;

    delta = arr->size;
    top = arr->depth - 1;
    while (top >= 0)
    {
        idx = phys_idx(arr, top);
        if (arr->elements[idx].rank > nbr)
        {
            tmp = arr->elements[idx].rank - nbr;
            if(tmp < delta)
            {
                delta = tmp;
                res = top;
            }
        }
        top--;
    }
    return (res);
}

void turk_alg(t_context *context)
{
    int target;
    int log_idx;
    int dist;

    pb(context);
    pb(context);
    target = context->b.elements[phys_idx(&context->b, 0)].rank;
    log_idx = find_element(&context->a, target);
    dist = context->a.depth - 1 - log_idx;
    while (dist)
        ra(context);
    pb(context);

}
