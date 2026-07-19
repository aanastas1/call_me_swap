#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


# include "../libft/libft.h"

typedef struct s_element
{
	int value; /* Value of the element */
	int rank; /* Rank of the element */
} t_element;

typedef struct s_arr {
    t_element *elements;
    int bottom; /* physical index of the cell containing logical element [0] */
    int depth; /* number of elements in the stack */
    int size; /* total capacity of the array */
}   t_arr;

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
    t_arr a;
    t_arr b;

    double disorder;

    t_strategy strategy;
    int bench_enabled;
   
    int op_total; /* total number of operations performed */
    int op_counts[COUNT]; /* array counts of each operation type */

    /* stdout-only ops are printed inside op_* */
} t_context;

void	put_error_n_exit(void);
void    *xalloc(size_t count, size_t type_size);

/* parse */
void parse_args(int argc, char **argv, t_context *context);
int validate_no_dups(int *values, int n);

/* disorder + ranks */
double compute_disorder_values(const int *values, int n);   /* returns [0..1] */
void   compute_ranks(t_context *context, const int *values, int size);            

void setup_stacks(t_context *context, int *values, int size);

/* sort helpers */
int  stack_is_sorted_asc(const t_arr *a); /* ascending: smaller ranks first on top */
void sort_small(t_context *context);                /* handles n<=3..5 safely via dedicated logic */

int phys_idx(t_arr *arr, int logical_idx);
void swap(t_arr *arr, int logical_idx1, int logical_idx2);

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

void turk_alg(t_context *context);

void    strategy_selector(t_context *context);
/* strategies */
void strategy_simple(t_context *context);
void strategy_medium(t_context *context);
void strategy_complex(t_context *context);
void strategy_adaptive(t_context *context);

/* bench */ //by anastasi side print count of operation, or sa ss 
void bench_print_and_counts(t_context *context, const char *strategy_name, const char *complex_class);


# endif