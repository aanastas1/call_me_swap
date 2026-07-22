<<<<<<< HEAD
int main(void)
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 19:28:39 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	put_error_n_exit(void)
>>>>>>> 38205b8 (Combined parsing and sorting algorithms.)
{
    return 0;
}
<<<<<<< HEAD
=======
static void	context_init(t_context *context)
{
	*context = (t_context){
    .a = { .elements = NULL, .depth = 0 },
    .b = { .elements = NULL, .depth = 0 },
    .disorder = 0.0,
    .strategy = NONE,
    .bench_enabled = 0,
    .op_total = 0,
    .op_counts = {0}
	};
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
	int idx_b;
	
	idx_a = 0;
	idx_b = 0;
	ft_putstr_fd("Stack A: (Value | Rank): [ ", 1);
	ft_putstr_fd("           Stack B: (Value | Rank): [\n", 1);
	while (idx_a < context->a.depth || idx_b < context->b.depth)
	{
		if (idx_a < context->a.depth)
		{
			ft_putstr_fd("              ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->a.elements[idx_a].rank, 1);
			if (idx_a == context->a.depth - 1)
			{
				ft_putstr_fd(" ]", 1);
			}
			/*else
				ft_putstr_fd("                                                         ", 1);*/
			idx_a++;
		}
		if (idx_b < context->b.depth)
		{
			if (idx_b == 0 && idx_a >= context->a.depth)
				ft_putstr_fd("                       ", 1);
			ft_putstr_fd("                       ", 1);
			ft_putnbr_fd(context->b.elements[idx_b].value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(context->b.elements[idx_b].rank, 1);
			if (idx_b == context->b.depth - 1)
				ft_putstr_fd(" ]", 1);
			idx_b++;
		}
		ft_putstr_fd("\n", 1);
		if (idx_a == context->a.depth)
			ft_putstr_fd("                       ", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	t_context context;

	
	if (argc < 2)
		return (0);
	context_init(&context); 
	
/*	printf("DEBUG: main start\n");*/
	parse_args(argc, argv, &context);
/*	printf("DEBUG: After parse_args\n");*/
	if (context.a.depth == 0) 
	{		
		free_all(&context);
		put_error_n_exit();
	}
	strategy_selector(&context);
	
/*	printf("DEBUG: After setup_stacks\n");*/
	printf("DEBUG:     depth.a = %d,                depth.b = %d\n", context.a.depth,  context.b.depth);
	print_stack_a_b(&context);

	//strategy_medium(&context);
	strategy_medium(&context);
	/*pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	print_stack_a_b(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	pb(&context);
	print_stack_a_b(&context);

	rrr(&context);
	print_stack_a_b(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	print_stack_a_b(&context);
	rb(&context);
	print_stack_a_b(&context);
	rb(&context);
	print_stack_a_b(&context);
	rr(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	rrr(&context);
	print_stack_a_b(&context);


	//turk_alg(&context);*/

	printf("Disorder: %.2f\n", context.disorder);
	


	printf("DEBUG:     depth.a = %d,                depth.b = %d\n", context.a.depth,  context.b.depth);
	printf("DEBUG:     operation_totaly = %d\n", context.op_total);
	print_stack_a_b(&context); /* print stack after small functions */

	if (context.bench_enabled)
		bench_print_and_counts(&context);


	free_all(&context);
	return (0);
}

>>>>>>> 38205b8 (Combined parsing and sorting algorithms.)
