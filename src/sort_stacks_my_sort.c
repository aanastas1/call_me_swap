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
        return ;
    }
    if (range == 2)
    {
        if (context->a.top->rank > context->a.top->next->rank)
            sa(context);
        // Исправлено: не отправляем элементы в B, просто возвращаемся
        return ;
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

void strategy_complex(t_context *context)
{
    int min_rank;
    int max_rank;

    min_rank = 0;
    max_rank = context->a.depth - 1;
    side_a(context, min_rank, max_rank);
    
}