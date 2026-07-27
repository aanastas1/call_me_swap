#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


# include "../libft/libft.h"

typedef struct s_node
{
	int	value;
	int	rank;

	struct s_node *next; // элемент ниже/следующий по кругу
	struct s_node *prev; // элемент выше/предыдущий по кругу
}	t_node;

typedef struct s_stack
{
	t_node	*top;   // текущая вершина стека
	int			depth; // количество элементов
}	t_stack;


typedef enum e_optype {
    SA, SB, SS,
    PA, PB,
    RA, RB, RR,
    RRA, RRB, RRR,
    COUNT
} t_operation_type;

typedef enum e_strategy {
    NONE,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE
} t_strategy;

typedef struct s_context {
    t_stack	a;
    t_stack	b;

    double disorder;

    t_strategy strategy;
    int bench_enabled;
   
    int op_total; /* total number of operations performed */
    int op_counts[COUNT]; /* array counts of each operation type */
    
    const char		*strategy_name;
	const char		*complexity;
    /* stdout-only ops are printed inside op_* */
 } t_context;
 
/*assistant functions*/

void	put_error_n_exit(void);
void    *xalloc(size_t count, size_t type_size);
void    free_stack(t_stack *stack);

/* parse */
void parse_args(int argc, char **argv, t_context *context);
int	parse_one_arg(char *arg, int **out_values, int *capacity, int *idx);
void setup_stacks(t_context *context, int *values, int size);

/* sort helpers */
int  stack_is_sorted_asc(t_stack *a); /* ascending: smaller ranks first on top */
void sort_small(t_context *context);                /* handles n<=3..5 safely via dedicated logic */
void    sort_three(t_context *context);
int	rank_at(t_stack *stack, int logical_index);
int	smallest_rank_index(t_stack *stack);
int	largest_rank_index(t_stack *stack);
int	rotations_to_top(t_stack *stack, int logical_index);

/* operation layer (must be the only place that prints ops) */
void sa(t_context *context);
void sb(t_context *context);
void ss(t_context *context);
void pa(t_context *context);
void pb(t_context *context);
void ra(t_context *context);
void rb(t_context *context);
void rr(t_context *context);
void rra(t_context *context);
void rrb(t_context *context);
void rrr(t_context *context);


/* strategies */
void    strategy_selector(t_context *context);
void strategy_simple(t_context *context);
void strategy_medium(t_context *context);
void strategy_complex(t_context *context);
void strategy_adaptive(t_context *context);

/* bench */ //by anastasi side print count of operation, or sa ss 
/*void bench_print_and_counts(t_context *context, const char *strategy_name, const char *complex_class);*/
void    bench_print_and_counts(t_context *context);
void	bench_putstr(const char *text);
void	bench_putnbr(int number);
void	bench_put_percent(double value);

# endif