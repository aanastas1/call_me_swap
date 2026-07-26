/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:37:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/26 21:27:57 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void side_b(t_context *context, int len);
static void side_a(t_context *context, int len);

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

static void sort_int_array(int *arr, int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

static int	find_pivot_b(t_context *context, int len)
{
	int		*arr;
	t_node	*node;
	int		pivot;
	int		i;

	if (len <= 0 || context->b.top == NULL)
		return (0);

	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);

	node = context->b.top;
	i = 0;

	while (i < len)
	{
		arr[i] = node->rank;
		node = node->next;
		i++;
	}

	sort_int_array(arr, len);

	pivot = arr[len / 2];

	free(arr);

	return (pivot);
}


int find_pivot_a(t_context *context, int len)
{
    int     *arr;
    t_node  *node;
    int     i;

    if (len <= 0 || context->a.top == NULL)
        return (0);
        
    arr = malloc(sizeof(int) * len);
    if (!arr)
		return (0);
  

    node = context->a.top;
    i = 0;
    while (i < len)
    {
        arr[i] = node->rank;
        node = node->next;
        i++;
    }

    sort_int_array(arr, len);

    i = arr[len / 2];

    free(arr);
    return (i);
}

static void side_a(t_context *context, int len)
{
    int pivot;
    int pushed;
    int rotated;
    int i;
    
    if (len <= 0)
        return;

    if (len <= 1)
        return;

    if (len == 2)
    {
        if (context->a.top->rank > context->a.top->next->rank)
            sa(context);
        return;
    }

    pivot = find_pivot_a(context, len);

    pushed = 0;
    rotated = 0;
    i = 0;

    while (i < len)
    {
        if (context->a.top->rank < pivot)
        {
            pb(context);
            pushed++;
        }
        else
        {
            ra(context);
            rotated++;
        }
        i++;
    }

    while (rotated > 0)
    {
        rra(context);
        rotated--;
    }

    side_a(context, len - pushed);
    side_b(context, pushed);
}

static void side_b(t_context *context, int len)
{
    int pivot;
    int pushed;
    int rotated;
    int i;

    if (len == 0)
        return;

    if (len == 1)
    {
        pa(context);
        return;
    }

    if (len == 2)
    {
        if (context->b.top->rank < context->b.top->next->rank)
            sb(context);


        pa(context);
        pa(context);
        return;
    }

    pivot = find_pivot_b(context, len);

    pushed = 0;
    rotated = 0;
    i = 0;

     while (i < len)
    {
        if (context->b.top->rank > pivot)
        {
            pa(context);
            pushed++;
        }
        else
        {
            rb(context);
            rotated++;
        }
        i++;
    }

    while (rotated > 0)
    {
        rrb(context);
        rotated--;
    }

    side_a(context, pushed);
    side_b(context, len - pushed);
}

void strategy_complex(t_context *context)
{
    side_a(context, context->a.depth);

    while (context->b.depth > 0)
        pa(context);
}
