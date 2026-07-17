/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:28:57 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/17 12:29:32 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted_asc(t_arr *stack)
{
	int	i;

	i = stack->depth - 1;
	while (i > 0)
	{
		if (stack->elements[phys_idx(stack, i)].rank
			> stack->elements[phys_idx(stack, i - 1)].rank)
			return (0);
		i--;
	}
	return (1);
}