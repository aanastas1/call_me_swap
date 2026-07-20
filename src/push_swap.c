/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:15:47 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/19 15:34:31 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    strategy_selector(t_context *context)
{
    if (context->strategy == NONE)
        strategy_adaptive(context);
    if (context->strategy == SIMPLE)
        strategy_simple(context);
    if (context->strategy == MEDIUM)
        strategy_medium(context);
    if (context->strategy == COMPLEX)
        strategy_complex(context);
    if (context->strategy == ADAPTIVE)
        strategy_adaptive(context);
}

void strategy_simple(t_context *context)
{(void)context;}
void strategy_medium(t_context *context)
{(void)context;}
void strategy_complex(t_context *context)
{(void)context;}
void strategy_adaptive(t_context *context)
{(void)context;}

int find_element(t_arr *arr, int nbr)
{
    int idx;
    int top;
    int delta;
    int res;
    int tmp;

    delta = arr->depth - 1;
    top = arr->depth - 1;
    idx = 0;
    while (top >= 0)
    {
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
    int idx;
    int dist;

    pb(context);
    pb(context);
    idx = 0;
    target = context->b.elements[idx].rank;
    idx = find_element(&context->a, target);
    dist = context->a.depth - 1 - idx;
    while (dist--)
        ra(context);
    pb(context);

}
