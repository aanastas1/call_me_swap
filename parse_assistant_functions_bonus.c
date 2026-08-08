/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 20:51:50 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;
	int		i;
	int		depth;

	if (!stack || !stack->top)
		return ;
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

static int	stack_is_asc_sorted(t_stack *s)
{
	t_node	*cur;
	int		i;

	if (!s || s->depth < 2)
		return (1);
	cur = s->top;
	i = 0;
	while (i < s->depth - 1)
	{
		if (cur->rank > cur->next->rank)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}

int	stacks_checker(t_context *context)
{
	if (!stack_is_asc_sorted(&context->a) || context->b.depth != 0)
		return (0);
	return (1);
}
