/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/14 20:07:47 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	ra(t_context *context)
{
	context->a.bottom = (context->a.bottom + 1) % context->a.size;
	context->op_counts[RA]++;
	context->op_total++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_context *context)
{
	context->b.bottom = (context->b.bottom + 1) % context->b.size;
	context->op_counts[RB]++;
	context->op_total++;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_context *context)
{
	context->a.bottom = (context->a.bottom + 1) % context->a.size;
	context->b.bottom = (context->b.bottom + 1) % context->b.size;
	context->op_counts[RR]++;
	context->op_total++;
	ft_putstr_fd("rr\n", 1);
}
