/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:47 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int	value;
	int	rank;
}	t_element;

typedef struct s_arr
{
	t_element	*elements;
	int			depth;
	int			capacity;
}	t_arr;

typedef enum e_operation_type
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
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	NONE
}	t_strategy;

typedef struct s_context
{
	t_arr			a;
	t_arr			b;
	int				op_total;
	int				op_counts[COUNT];
	t_strategy		strategy;
	int				bench_enabled;
	double			disorder;
	const char		*strategy_name;
	const char		*complexity;
}	t_context;

int		parse_args(int argc, char **argv, int **out_values,
			t_context *context);
int		ft_strcmp(const char *first, const char *second);
int		count_words(const char *source);
int		parse_numbers(const char *source, int *values, int *index);
int		validate_no_dups(int *values, int count);
int		init_context(t_context *context, int capacity);
void	free_context(t_context *context);

double	compute_disorder_values(const int *values, int count);
int		*compute_ranks(const int *values, int count);
void	setup_stacks(t_context *context, const int *values,
			const int *ranks, int count);

int		stack_is_sorted_asc(t_arr *stack);
void	sort_small(t_context *context);
int		rank_at(t_arr *stack, int logical_index);
int		smallest_rank_index(t_arr *stack);
int		largest_rank_index(t_arr *stack);
int		rotations_to_top(t_arr *stack, int logical_index);

void	swap(t_arr *stack, int first_index, int second_index);
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

void	strategy_simple(t_context *context);
void	strategy_medium(t_context *context);
void	strategy_radix_binary(t_context *context);
void	strategy_radix_base4(t_context *context);
void	radix4_split_halves(t_context *context, int shift, int count);
void	radix4_join_lower(t_context *context, int shift, int zero, int one);
void	radix4_join_upper(t_context *context, int shift, int two, int three);
void	radix4_rotate_a(t_context *context, int steps);
void	strategy_complex(t_context *context);
void	strategy_adaptive(t_context *context);

void	bench_putstr(const char *text);
void	bench_putnbr(int number);
void	bench_put_percent(double value);
void	bench_print_and_counts(t_context *context);

#endif
