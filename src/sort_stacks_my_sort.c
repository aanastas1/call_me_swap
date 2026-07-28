/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/26 22:17:16 by aloiko           ###   ########.fr       */
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
}

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
}*/
/*
static void sort_small_b_down(t_context *context)
{
    int a;
    int b;
    int c;

    if (context->b.depth == 0 || context->b.depth == 1)
        return;
    a = context->b.top->rank;
    b = context->b.top->next->rank;
    if (context->b.depth == 2 && a > b)
        return ;
    else if (context->b.depth == 2 && a < b)
    {
        sb(context);
        return ;
    }
    c = context->b.top->next->next->rank;
    if (c < b && b < a)
        return ;
    if (a < b && a < c)
        rb(context);
    else if (b < a && b < c)
        rrb(context);
    if (context->b.top->rank < context->b.top->next->rank)
        sb(context);
}

static void sort_small_a_top(t_context *context)
{
    int a;
    int b;
    int c;

    if (context->a.depth <= 1)
        return;
    a = context->a.top->rank;
    b = context->a.top->next->rank;
    if (context->a.depth == 2 && a < b)
        return ;
    else if (context->a.depth == 2 && a > b)
    {
        sa(context);
        return;
    }
    c = context->a.top->next->next->rank;
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
}*/

static void side_a(t_context *context, int min_rank, int max_rank)
{
    int range;
    int delimiter;
    int count;
    int start_rank;

    start_rank = -1;
    range = max_rank - min_rank + 1;

    if (range == 1)
    {
        return;
    }
    if (range == 2)
    {
        if (context->a.top->rank > context->a.top->next->rank)
            sa(context);
        // Исправлено: не отправляем элементы в B, просто возвращаемся
        return;
    }

    printf("ENTER side_a(%d,%d) depthA=%d depthB=%d\n",
        min_rank, max_rank, context->a.depth, context->b.depth);

    delimiter = (min_rank + max_rank) / 2;
    count = delimiter - min_rank;

    while (count)
    {
        if (context->a.top->rank < delimiter)
        {
            pb(context);
            count--;
        }
        else
        {
            if (start_rank == -1)
                start_rank = context->a.top->rank;
            ra(context);
        }        
    }

    // Восстанавливаем порядок в стеке A, если были вращения
    if (start_rank != -1)
    {
        while (context->a.top->rank != start_rank)
            rra(context);
    }

    printf("CALL side_a(%d,%d)\n", delimiter, max_rank);
    side_a(context, delimiter, max_rank);  // сортируем большую часть (в A)

    printf("CALL side_b(%d,%d)\n", min_rank, delimiter - 1);
    side_b(context, min_rank, delimiter - 1);  // сортируем меньшую часть (в B)
}

static void side_b(t_context *context, int min_rank, int max_rank)
{
    int range;
    int delimiter;
    int count;
    int start_rank;

    start_rank = -1;

    range = max_rank - min_rank + 1;

    if (range == 1)
    {
        pa(context);
        return;
    }
    if (range == 2)
    {
        if (context->b.top->rank < context->b.top->next->rank)
            sb(context);
        // Исправлено: всегда переносим оба элемента в A (без проверки depth)
        pa(context);
        pa(context);
        return;
    }

    printf("ENTER side_b(%d,%d) depthA=%d depthB=%d\n",
        min_rank, max_rank, context->a.depth, context->b.depth);

    delimiter = (min_rank + max_rank + 1) / 2;
    count = max_rank - delimiter + 1;

    while (count)
    {
        if (context->b.top->rank >= delimiter)
        {
            pa(context);
            count--;
        }
        else
        {
            if (start_rank == -1)
                start_rank = context->b.top->rank;
            rb(context);
        }    
    }

    if (start_rank != -1)
    {
        while (context->b.top->rank != start_rank)
            rrb(context);
    }

    // !!! КЛЮЧЕВОЕ ИСПРАВЛЕНИЕ: сначала сортируем в A элементы >= delimiter,
    // которые только что были перенесены из B
    side_a(context, delimiter, max_rank);
    // затем сортируем оставшуюся в B часть < delimiter
    side_b(context, min_rank, delimiter - 1);
}

static void sort_stacks(t_context *context, int min_rank, int max_rank)
{
    int delimiter;
    int count;

    if (context->a.depth <= 3)
    {
        sort_small(context);
        return;
    }

    delimiter = (min_rank + max_rank) / 2;
    count = delimiter - min_rank;
    printf("PARTITION A BEFORE: ");
    t_node *x = context->a.top;
    for (int i = 0; i < context->a.depth; i++)
    {
        printf("%d ", x->rank);
        x = x->next;
    }
    printf("\n");
    while (count)
    {
        if (context->a.top->rank < delimiter)
        {
            pb(context);
            count--;
        }
        else
            ra(context);
    }
    printf("CHECK RANGE [%d..%d]: ", min_rank, max_rank);
    t_node *p = context->a.top;

    int range = max_rank - min_rank + 1;

    for (int i = 0; i < range; i++)
    {
        printf("%d ", p->rank);
        p = p->next;
    }
    printf("\n");

    side_a(context, delimiter, max_rank);
    printf("CHECK RANGE [%d..%d]: ", min_rank, max_rank);
    p = context->a.top;

    for (int i = 0; i < range; i++)
    {
        printf("%d ", p->rank);
        p = p->next;
    }
    printf("\n");

    side_b(context, min_rank, delimiter - 1);
    
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