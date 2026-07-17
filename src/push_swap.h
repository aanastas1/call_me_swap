#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_element
{
	int		value; // 42
	int		rank; // вычислянем по возрастанию 
} t_element;

typedef struct s_stack
{
	t_element	*numbers;
	int         size;	// актуальный размер 
	int         capacity; // вместительность
} t_stack;

typedef enum e_optype 
{
	SA, SB, SS, // SA = 0, SB = 1..OP_COUNT = 11
	PA, PB,
	RA, RB, RR,
	RRA, RRB, RRR,
	OP_COUNT
} t_operation_type;

typedef struct s_arr
{
	t_element	*elements;
	int			bottom;
	int			depth;
	int			size;
}t_arr;

typedef enum e_strategy {
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE,
    NONE
} t_strategy;

typedef struct s_context
{
	t_arr		a;
	t_arr		b;
	t_strategy	strategy;
	int		bench_enabled;
	long		op_total;
	long		op_counts[OP_COUNT];
} t_context;

/* array stack */
int	    stack_init(t_stack *stack, int capacity); // ✅ 
void	stack_clear(t_stack *stack);			// ✅ 
int	    stack_add_top(t_stack *stack, int value, int rank); // ✅ 
int	    stack_remove_top(t_stack *stack, t_element *out); // ✅
int 	stack_is_empty(const t_stack *stack); // ✅ 
int	    stack_is_sorted_asc(const t_stack *a); // ✅ 

/* parse */
int		parse_args(int argc, char **argv, int **out_values,
			t_context *context);
int		validate_ints_and_no_dups(int *values, int n);

/* disorder + ranks */
double	compute_disorder_values(const int *values, int n);
int		*compute_ranks(const int *values, int n);

/* strategies */
void	sort_small(t_context *context);
void	strategy_simple(t_context *context, int n);
void	strategy_medium(t_context *context, int n);
void	strategy_complex(t_context *context, int n);
void	strategy_adaptive(t_context *context, int n, double disorder);

/* operations: every op_* must call op_record exactly once. */
void	op_record(t_context *context, t_operation_type operation);
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

/* bench: output goes to stderr, never stdout. */
void	bench_print_and_counts(t_context *context, double disorder,
	const char *strategy_name, const char *complex_class);

#endif
