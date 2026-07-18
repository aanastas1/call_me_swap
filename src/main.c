/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/18 16:26:36 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	put_error_n_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
static void	context_init(t_context *context)
{
    ft_bzero(&context, sizeof(context)); 
}


static void	free_all(t_context *context)
{
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
	t_context	context;

	if (argc < 2)
		return (0);
	context_init(&context); 
	
	printf("DEBUG: main start\n");
	parse_args(argc, argv, &context);
	printf("DEBUG: After parse_args\n");
	if (context.a.size == 0) 
	{		
		free_all(&context);
		put_error_n_exit();
	}
	
	
	printf("DEBUG: After setup_stacks\n");
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	print_stack_a_b(&context); /*print stack before small functions*/

	sa(&context);
	pb(&context);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	pb(&context);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	pb(&context);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	pb(&context);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	pb(&context);
	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
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

	printf("Disorder: %.2f\n", context.disorder);
	printf("DEBUG: n = %d\n", context.a.size);
		
	printf("DEBUG: int size = %zu\n", sizeof(int));
    printf("DEBUG: double size = %zu\n", sizeof(double));
	printf("DEBUG: context.disorder size = %zu\n", sizeof(context.disorder));
	printf("DEBUG: a size = %zu\n", sizeof(context.a));
	printf("DEBUG: strategy size = %zu\n", sizeof(context.strategy));
	printf("DEBUG: op_total size = %zu\n", sizeof(context.op_total));
	printf("DEBUG: op_counts[COUNT] size = %zu\n", sizeof(context.op_counts[COUNT]));
	printf("DEBUG: bench_enabled size = %zu\n", sizeof(context.bench_enabled));


	printf("DEBUG: depth.a = %d, size.a = %d              depth.b = %d, size.b = %d\n", context.a.depth, context.a.size, context.b.depth, context.b.size);
	
	print_stack_a_b(&context); /* print stack after small functions */

	free_all(&context);
	return (0);
}

