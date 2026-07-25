/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 21:11:24 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void side_b(t_context *context, int min_rank, int max_rank);
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
/*
int rank_at(t_stack *s, int i)
{
    t_node *cur = s->top;

    while (i-- > 0)
        cur = cur->next;
    return cur->rank;
}*/

void push_it_b(t_context *context, int idx)
{
    if (idx < context->a.depth / 2)
    {
        while (idx--)
            ra(context);
        pb(context);
      //  print_stack_a_b(context);
    }
    else
    {
        idx = context->a.depth - idx;
        while (idx--)
            rra(context);
        pb(context);
      //  print_stack_a_b(context);
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
   // print_stack_a_b(context);
}

static void sort_small_b_down(t_context *context)
{
    int a;
    int b;
    int c;

    if (context->b.depth == 0 || context->b.depth == 1)
        return;

    a = rank_at(&context->b, 0);
    b = rank_at(&context->b, 1);

    if (context->b.depth == 2 && a < b)
    {
        sb(context);
        return ;
    }

    c = rank_at(&context->b, 2);

    if (c < b && b < a)
        return;
    if (a < b && a < c)
        rb(context);
    else if (b < a && b < c)
        rrb(context);
    if (rank_at(&context->b, 0) < rank_at(&context->b, 1))
        sb(context);
}

static void sort_small_a_top(t_context *context)
{
    if (context->a.depth <= 1)
        return;

    int a = rank_at(&context->a, 0);
    int b = rank_at(&context->a, 1);

    if (context->a.depth == 2)
    {
        if (a > b)
            sa(context);
        return;
    }

    int c = rank_at(&context->a, 2);

    if (a < b && b < c)
        return;

    if (a < c && c < b)
    {
        sa(context);
        ra(context);
        return;
    }

    if (b < a && a < c)
    {
        sa(context);
        return;
    }

    if (b < c && c < a)
    {
        ra(context);
        return;
    }

    if (c < a && a < b)
    {
        rra(context);
        return;
    }

    if (c < b && b < a)
    {
        sa(context);
        rra(context);
        return;
    }
}

static void side_a(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;

    if (context->a.depth <= 3)
    {
        sort_small_a_top(context);
        return;
    }

    delimiter = (min_rank + max_rank) / 2;
    count = context->a.depth / 2;

    i = 0;
    while (count && i < context->a.depth)
    {
        if (rank_at(&context->a, i) < delimiter)
        {
            push_it_b(context, i);
            count--;
            i = -1;
        }
        i++;
    }
    side_a(context, delimiter, max_rank);
}

static void side_b(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;

    if (context->b.depth <= 3)
    {
        sort_small_b_down(context);
        return;
    }

    delimiter = (min_rank + max_rank) / 2;
    count = context->b.depth / 2;

    i = 0;
    while (count && i < context->b.depth)
    {
        if (rank_at(&context->b, i) >= delimiter)
        {
            push_it_a(context, i);
            count--;
            i = -1;
        }
        i++;
    }

    side_b(context, min_rank, delimiter);
   // while (context->b.depth > 0)
        //pa(context);
}

static void sort_stacks(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int i;
    int count;

    if (context->a.depth <= 3)
    {
        sort_small(context);
        return;
    }

    delimiter = (min_rank + max_rank) / 2;
    count = context->a.depth / 2;

    i = 0;
    while (count && i < context->a.depth)
    {
        if (rank_at(&context->a, i) < delimiter)
        {
            push_it_b(context, i);
            count--;
            i = -1;
        }
        i++;
    }

    side_a(context, delimiter, max_rank);
    side_b(context, min_rank, delimiter);
}

void strategy_complex(t_context *context)
{
    int min_rank;
    int max_rank;

    min_rank = 0;
    max_rank = context->a.depth - 1;
    sort_stacks(context, min_rank, max_rank);
    while (context->b.depth > 0)
             pa(context);

}