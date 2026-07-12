#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft.h"

typedef struct s_arr {
    int *num;
    int start;
    int len;
    int size;
}   t_arr;

typedef enum e_optype {
    SA, SB, SS,
    PA, PB,
    RA, RB, RR,
    RRA, RRB, RRR,
    COUNT
} t_operation_type;

typedef enum e_strategy {
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTIVE,
    NONE
} t_strategy;

typedef struct s_context {
    t_arr a;
    t_arr b;

    t_strategy strategy;
    int bench_enabled;
    long op_total;
    long op_counts[COUNT];

    /* stdout-only ops are printed inside op_* */
} t_context;

/* parse */
int  parse_args(int argc, char **argv, int **out_values, t_context *context);
int  validate_ints_and_no_dups(int *values, int n);

/* disorder + ranks */
double compute_disorder_values(const int *values, int n);   /* returns [0..1] */
int   *compute_ranks(const int *values, int n);             /* returns n ints */

/* sort helpers */
int  stack_is_sorted_asc(const t_arr *a); /* ascending: smaller ranks first on top */
void sort_small(t_context *context);                /* handles n<=3..5 safely via dedicated logic */

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
void strategy_simple(t_context *context, int n);
void strategy_medium(t_context *context, int n);
void strategy_complex(t_context *context, int n);
void strategy_adaptive(t_context *context, int n, double disorder);

/* bench */ //by anastasi side print count of operation, or sa ss 
void bench_print_and_counts(t_context *context, double disorder,
const char *strategy_name, const char *complex_class);

# endif