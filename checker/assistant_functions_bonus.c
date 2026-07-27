/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/27 21:03:32 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

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

int	stack_is_sorted_asc(t_stack *stack)
{
	int	index;

	index = 1;
	while (index < stack->depth)
	{
		if (rank_at(stack, index - 1) > rank_at(stack, index))
			return (0);
		index++;
	}
	return (1);
}

int stacks_checker(t_context *context)
{
    if(!stack_is_sorted_asc(&context->a))
        return (0);
    if(context->b.depth != 0)
        return (0);
    return (0);
}