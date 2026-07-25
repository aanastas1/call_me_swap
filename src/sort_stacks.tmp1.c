/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.tmp1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 21:06:28 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void side_b(t_context *context, int min_rank, int max_rank);*/
static void side_a(t_context *context, int min_rank, int max_rank);

/*static int find_index_max_in_b(t_context *context, int min_rank, int max_rank_exclusive)
{
    int i, best_i = 0;
    int best_rank = -1; // rank >= 0
    i = 0;
    while ( i < context->b.depth)
    {
        int r = context->b.elements[i].rank;
        if (r >= min_rank && r < max_rank_exclusive && r > best_rank)
        {
            best_rank = r;
            best_i = i;
        }
        i++;
    }
    return best_i;
}

static void rotate_b_to_top(t_context *context, int idx)
{
    if (idx < context->b.depth / 2)
        while (idx--) rb(context);
    else
    {
        idx = context->b.depth - idx;
        while (idx--) rrb(context);
    }
}

static void merge_b_a(t_context *context, int min_rank, int delimiter, int max_rank)
{
    (void)max_rank;
    while (context->b.depth)
    {
        int idx = find_index_max_in_b(context, min_rank, delimiter); // B: [min, delimiter)
        rotate_b_to_top(context, idx);
        pa(context); // кладём сверху A
    }
}*/

void push_it_b(t_context *context, int idx)
{
    printf("DEBUG: push_it_b start\n");
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
    printf("DEBUG: push_it_a start\n");
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
    print_stack_a_b(context);
}

static void side_a(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;
   
    printf("DEBUG: side_a start\n");
    if (context->a.depth <= 5)
    {
        printf("DEBUG: small_5_a start\n");
        sort_small(context);
        return ;
    }
    delimiter = (min_rank + max_rank) / 2;
    count = context->a.depth / 2 ;
    i = 0;
    while (count)
    {
       if (context->a.elements[i].rank < delimiter)
       {
            push_it_b(context, i);
            count--;
            i = -1;
        }
            i++;
    }
    side_a(context, delimiter, max_rank);
    print_stack_a_b(context);
    /*side_b(context, min_rank, delimiter);
    print_stack_a_b(context);*/
}
/*
static void side_b(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;
    
    if (context->b.depth <= 1)
    {
        print_stack_a_b(context);
        return ;
    }

    delimiter = (min_rank + max_rank) / 2;
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
    side_b(context, min_rank, delimiter);
    print_stack_a_b(context);
    side_a(context, delimiter, max_rank);
    print_stack_a_b(context);
}*/


static void sort_stacks(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;
   
    printf("DEBUG: sort_stack start\n");
    if (context->a.depth <= 5)
    {
        sort_small(context);
        return ;
    }
    delimiter = (min_rank + max_rank) / 2;
    count = context->a.depth / 2;
    i = 0;
    while (count)
    {
       if (context->a.elements[i].rank < delimiter)
       {
            push_it_b(context, i);
            count--;
            i = -1;
        }
            i++;
    }
    side_a(context, delimiter, max_rank);
    /*side_b(context, min_rank, delimiter);*/
    /*merge_b_a(context, min_rank, delimiter, max_rank);*/
      
}


void strategy_complex(t_context *context)
{
    printf("DEBUG: strategy_complex start\n");
    int min_rank;
    int max_rank;

    min_rank = 0;
    max_rank = context->a.depth;
    sort_stacks(context, min_rank, max_rank);
}
