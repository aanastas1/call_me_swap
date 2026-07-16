/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_n_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:15:04 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/16 16:43:01 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	sa(t_context *context)
{
	int			top_logic_idx;
	
	top_logic_idx = context->a.depth - 1;
	if (context->a.depth <= 1) /* Not enough elements to swap */
		return ;
	swap(&context->a, top_logic_idx, top_logic_idx - 1);
	context->op_counts[SA]++;
	context->op_total++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_context *context)
{
	int			top_logic_idx;

	if (context->b.depth <= 1)
		return ;
	top_logic_idx = context->b.depth - 1;
	swap(&context->b, top_logic_idx, top_logic_idx - 1);
	context->op_counts[SB]++;
	context->op_total++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_context *context)
{
	int			top_a_logic_idx;
	int			top_b_logic_idx;

	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
	{
		top_a_logic_idx = context->a.depth - 1;
		swap(&context->a, top_a_logic_idx, top_a_logic_idx - 1);
	}
	if (context->b.depth > 1)
	{
		top_b_logic_idx = context->b.depth - 1;
		swap(&context->b, top_b_logic_idx, top_b_logic_idx - 1);
	}
	context->op_counts[SS]++;
	context->op_total++;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_context *context)
{
	int			top_a_logic_idx;
	int			top_b_logic_idx;
	int			idx_a;
	int			idx_b;

	if (context->b.depth == 0)
		return ;
	context->a.depth++;
	top_a_logic_idx = context->a.depth - 1;
	top_b_logic_idx = context->b.depth - 1;

	idx_a = phys_idx(&context->a, top_a_logic_idx);
	idx_b = phys_idx(&context->b, top_b_logic_idx);
	context->a.elements[idx_a] = context->b.elements[idx_b];
	context->b.depth--;
	context->op_counts[PA]++;
	context->op_total++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_context *context)
{
	int			top_a_logic_idx;
	int			top_b_logic_idx;
	int			idx_a;
	int			idx_b;
	
	if (context->a.depth == 0)
		return ;
	context->b.depth++;
	top_a_logic_idx = context->a.depth - 1;
	top_b_logic_idx = context->b.depth - 1;
	idx_a = phys_idx(&context->a, top_a_logic_idx);
	idx_b = phys_idx(&context->b, top_b_logic_idx);
	context->b.elements[idx_b] = context->a.elements[idx_a];
	context->a.depth--;
	context->op_counts[PB]++;
	context->op_total++;
	ft_putstr_fd("pb\n", 1);
}
