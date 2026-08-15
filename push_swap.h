/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:36:36 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/15 18:37:13 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				rank;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		depth;
}	t_stack;

typedef enum e_optype
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	COUNT
}	t_operation_type;

typedef enum e_strategy
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_context
{
	t_stack		a;
	t_stack		b;
	double		disorder;
	t_strategy	strategy;
	int			bench_enabled;
	int			op_total;
	int			op_counts[COUNT];
	const char	*strategy_name;
	const char	*complexity;
}	t_context;
/*assistant functions*/
void	put_error(void);
void	put_operation(char *str);
void	*xalloc(size_t count, size_t type_size);
void	free_stack(t_stack *stack);
/* parse */
void	parse_args(int argc, char **argv, t_context *context);
int		parse_one_arg(char *arg, int **out_values, int *capacity, int *idx);
void	setup_stacks(t_context *context, int *values, int size);
/* sort helpers */
int		stack_is_sorted_asc(t_stack *a);
void	sort_small(t_context *context);
void	sort_three(t_context *context);
int		rank_at(t_stack *stack, int logical_index);
int		smallest_rank_index(t_stack *stack);
int		largest_rank_index(t_stack *stack);
int		rotations_to_top(t_stack *stack, int logical_index);
/* operation layer (must be the only place that prints ops) */
void	sa(t_context *context);
void	sb(t_context *context);
void	ss(t_context *context);
void	pa(t_context *context);
void	pb(t_context *context);
void	ra(t_context *context);
void	rb(t_context *context);
void	rr(t_context *context);
void	rra(t_context *context);
void	rrb(t_context *context);
void	rrr(t_context *context);
/* strategies */
void	strategy_selector(t_context *context);
void	strategy_simple(t_context *context);
void	strategy_medium(t_context *context);
void	strategy_complex(t_context *context);
void	strategy_adaptive(t_context *context);
/* bench print count of operation */
void	bench_print_and_counts(t_context *context);
void	bench_putstr(const char *text);
void	bench_putnbr(int number);
void	bench_put_percent(double value);

#endif
