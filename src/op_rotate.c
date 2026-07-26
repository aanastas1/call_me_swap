/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:17:37 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/26 19:35:10 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	ra(t_context *context)
{
	if (context->a.depth <= 1)
		return;
	context->a.top = context->a.top->next;
	context->op_counts[RA]++;
	context->op_total++;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	printf("AFTER ra\n");
	check_circle(&context->a, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);

}

void	rb(t_context *context)
{
	if (context->b.depth <= 1)
		return;
	context->b.top = context->b.top->next;
	context->op_counts[RB]++;
	context->op_total++;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	printf("AFTER rb\n");
	check_circle(&context->a, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
}

void	rr(t_context *context)
{
	if (context->a.depth <= 1 && context->b.depth <= 1)
		return ;
	if (context->a.depth > 1)
		context->a.top = context->a.top->next;
	if (context->b.depth > 1)
		context->b.top = context->b.top->next;
	printf("AFTER rr\n");
	check_circle(&context->a, "A");
	check_circle(&context->b, "B");
	print_circle(&context->a);
	print_circle(&context->b);
	context->op_counts[RR]++;
	context->op_total++;
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
