/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 18:35:09 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void *xalloc(size_t count, size_t elem_size)
{
	size_t total;
	void *ptr;

    if (elem_size != 0 && count > SIZE_MAX / elem_size)
       return (NULL); 
    total = count * elem_size;
    ptr = malloc(total);
    return (ptr);
}

void	put_error_n_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void free_stack(t_stack *stack)
{
    t_node *curr;
	t_node *next;
    int i;
    int depth;

    if (!stack || !stack->top)
        return;
    curr = stack->top;
    depth = stack->depth;
    i = 0;
    while (i < depth)
    {
        next = curr->next;
        free(curr);
        curr = next;
        i++;
    }
    stack->top = NULL;
    stack->depth = 0;
}

static int stack_is_asc_sorted(t_stack *s)
{
	t_node	*cur;

	if (!s || s->depth < 2)
		return (1);

	cur = s->top; // верх стека
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int stacks_checker(t_context *context)
{
    if(!stack_is_asc_sorted(&context->a))
        return (0);
    if(context->b.depth != 0)
        return (0);
    return (1);
}