/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/18 01:08:10 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

static void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	
}

static void	free_all(t_context *context, int *values)
{

	if (values)
		free(values);
	if (context->a.elements)
		free(context->a.elements);
	if (context->b.elements)
		free(context->b.elements);
}

void print_stack_a_b(t_context *context)
{
	int	idx_a;
	int top_a;
	int idx_b;
	int top_b;

	top_a = context->a.depth - 1;
	top_b = context->b.depth - 1;
	ft_putstr_fd("Stack A: (Value | Rank): [ ", 1);
	ft_putstr_fd("                 Stack B: (Value | Rank): [\n", 1);
	while (top_a >= 0 || top_b >= 0)
	{
		if (top_a >= 0)
		{
			idx_a = phys_idx(&context->a, top_a);
			ft_putstr_fd("              ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].rank, 1);
			if (top_a == 0)
				ft_putstr_fd(" ]", 1);
			ft_putstr_fd("                       ", 1);
			top_a--;
		}
		if (top_b >= 0)
		{
			idx_b = phys_idx(&context->b, top_b);
			ft_putnbr_fd(context->b.elements[idx_b].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->b.elements[idx_b].rank, 1);
			if (top_b == 0)
				ft_putstr_fd(" ]", 1);
			top_b--;
		}
		ft_putstr_fd("             \n", 1);
		if (top_a < 0)
			ft_putstr_fd("                                            ", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	int		*values;
	int		count_of_nbr;
	double	disorder;
	t_context	context;

	values = NULL;
	ft_bzero(&context, sizeof(context)); 
	if (argc < 2)
		return (0);
	printf("DEBUG: main start\n");
	count_of_nbr = parse_args(argc, argv, &values, &context);
	printf("DEBUG: After parse_args\n");
	if (count_of_nbr <= 0 || !values) 
	{
		put_error();
		free_all(&context, values);
		return (0);
	}
	
	if (!validate_no_dups(values, count_of_nbr))
	{
		put_error();
		free_all(&context, values);
		return (0);
	}
	setup_stacks(&context, values, count_of_nbr);
	printf("DEBUG: After setup_stacks\n");
	disorder = compute_disorder_values(values, count_of_nbr);
	print_stack_a_b(&context); /*print stack before small functions*/

	sa(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	ra(&context);
	ra(&context);
	rr(&context);
	rr(&context);
	rrr(&context);
	rb(&context);


	//turk_alg(&context);

	printf("Disorder: %.2f\n", disorder);
	printf("DEBUG: n = %d\n", count_of_nbr);
	printf("DEBUG: values = %d\n", *values);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	
	print_stack_a_b(&context); /* print stack after small functions */

	free_all(&context, values);
	return (0);
}

