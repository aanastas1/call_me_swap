# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>




typedef struct s_node
{
    int             value;      // 42
    int             rank;       // позиция числа в отсортированном массиве
    struct s_node   *next;      // указатель на следующий элемент
}   t_node;

typedef struct s_stack
{
    t_node          *top;       // первый элемент стека
    t_node          *bottom;    // последний элемент стека
    int             size;       // сколько элементов в стеке
}   t_stack;

// adrii 

typedef struct s_node {
    int value;
    int rank;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

typedef enum e_optype {
    OP_SA, OP_SB, OP_SS,
    OP_PA, OP_PB,
    OP_RA, OP_RB, OP_RR,
    OP_RRA, OP_RRB, OP_RRR,
    OP_COUNT
} t_optype;

typedef struct s_ctx {
    t_stack a;
    t_stack b;

    int bench_enabled;
    long op_total;
    long op_counts[OP_COUNT];

    /* stdout-only ops are printed inside op_* */
} t_ctx;

/* parse */
int  parse_args(int argc, char **argv, int **out_values);
int  validate_ints_and_no_dups(int *values, int n);

/* disorder + ranks */
double compute_disorder_values(const int *values, int n);   /* returns [0..1] */
int   *compute_ranks(const int *values, int n);             /* returns n ints */

/* stack */
void stack_init(t_stack *s);
void stack_clear(t_stack *s);
void stack_push_top(t_stack *s, int value, int rank);
int  stack_is_empty(const t_stack *s);

/* sort helpers */
int  stack_is_sorted_asc(const t_stack *a); /* ascending: smaller ranks first on top */
void sort_small(t_ctx *ctx);                /* handles n<=3..5 safely via dedicated logic */

/* operation layer (must be the only place that prints ops) */
void op_sa(t_ctx *ctx);
void op_sb(t_ctx *ctx);
void op_ss(t_ctx *ctx);
void op_pa(t_ctx *ctx);
void op_pb(t_ctx *ctx);
void op_ra(t_ctx *ctx);
void op_rb(t_ctx *ctx);
void op_rr(t_ctx *ctx);
void op_rra(t_ctx *ctx);
void op_rrb(t_ctx *ctx);
void op_rrr(t_ctx *ctx);

/* strategies */
void strategy_simple(t_ctx *ctx, int n);
void strategy_medium(t_ctx *ctx, int n);
void strategy_complex(t_ctx *ctx, int n);
void strategy_adaptive(t_ctx *ctx, int n, double disorder);

/* bench */
void bench_print_and_counts(t_ctx *ctx, double disorder,
const char *strategy_name, const char *complex_class);

# endif