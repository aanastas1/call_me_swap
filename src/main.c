/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 14:27:48 by aloiko           ###   ########.fr       */
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
	ft_memset(context, 0, sizeof(*context));
    context->strategy = NONE;
    context->bench_enabled = 0;
}

static void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;
	t_node	*start;

	if (!stack || !stack->top)
		return;

	start = stack->top;
	curr = start;

	// Проходим по кругу, пока не вернемся к start
	do {
		next = curr->next;
		free(curr);
		curr = next;
	} while (curr != start);

	stack->top = NULL;
}

static void	free_all(t_context *context)
{
	if (!context)
		return;

	free_stack(&context->a);
	free_stack(&context->b);
}

void print_stack_a_b(t_context *context)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*start_a;
	t_node	*start_b;
	int		idx_a;
	int		idx_b;
	int		done_a;
	int		done_b;

	if (!context->a.top && !context->b.top)
	{
		ft_putstr_fd("Stack A: []\n           Stack B: []\n", 1);
		return;
	}

	start_a = context->a.top;
	start_b = context->b.top;
	curr_a = start_a;
	curr_b = start_b;
	idx_a = 0;
	idx_b = 0;
	done_a = (start_a == NULL);
	done_b = (start_b == NULL);
	ft_putstr_fd("Stack A: (Value | Rank): [ ", 1);
	ft_putstr_fd("           Stack B: (Value | Rank): [\n", 1);
	while (!done_a || !done_b)
	{
		if (!done_a)
		{
			if (idx_a >= 0 || done_b)
				ft_putstr_fd("              ", 1);
			ft_putnbr_fd(curr_a->value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(curr_a->rank, 1);
			if (curr_a->next == start_a)
			{
				ft_putstr_fd(" ]", 1);
			}
			/*else
				ft_putstr_fd("                                                         ", 1);*/
			curr_a = curr_a->next;
			idx_a++;
			if (curr_a == start_a)
				done_a = 1;
		}	
		else
		{
			if (!done_b)
				ft_putstr_fd("              ", 1);
		}
		if (!done_b)
		{
			if (idx_b >= 0 || done_a)
				ft_putstr_fd("                       ", 1);
			else if (idx_b > 0)
				ft_putstr_fd("                       ", 1);
			ft_putnbr_fd(curr_b->value, 1);
			ft_putstr_fd(" | ", 1);
			ft_putnbr_fd(curr_b->rank, 1);
			if (curr_b->next == start_b)
				ft_putstr_fd(" ]", 1);
			else
				ft_putstr_fd(" ", 1);
			curr_b = curr_b->next;
			idx_b++;
			if (curr_b == start_b)
				done_b = 1;
		}
		else
		{
			if (!done_a)
				ft_putstr_fd("                       ", 1);
		}
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	t_context context;

	
	if (argc < 2)
		return (1);
	context_init(&context); 
	
/*	printf("DEBUG: main start\n");*/
	parse_args(argc, argv, &context);
/*	printf("DEBUG: After parse_args\n");*/
	if (context.a.depth == 0) 
	{		
		free_all(&context);
		put_error_n_exit();
	}
	//strategy_selector(&context);
	
	printf("DEBUG: After setup_stacks\n");
	printf("DEBUG:     depth.a = %d,                depth.b = %d\n", context.a.depth,  context.b.depth);
	print_stack_a_b(&context);

	strategy_selector(&context);
	//strategy_medium(&context);
	//strategy_complex(&context);
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
	print_stack_a_b(&context);*/


	//turk_alg(&context);

	printf("Disorder: %.2f\n", context.disorder);
	


	printf("DEBUG:     depth.a = %d,                depth.b = %d\n", context.a.depth,  context.b.depth);
	printf("DEBUG:     operation_totaly = %d\n", context.op_total);
	print_stack_a_b(&context); /* print stack after small functions */

	if (context.bench_enabled)
		bench_print_and_counts(&context);


	free_all(&context);
	return (0);
}

