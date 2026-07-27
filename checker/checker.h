#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


# include "../libft/libft.h"


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
#endif 

typedef struct s_node
{
	int	value;
	int	rank;

	struct s_node *next; 
	struct s_node *prev; 
}	t_node;

typedef struct s_stack
{
	t_node	*top;  
	int			depth;
}	t_stack;

typedef struct s_context {
    t_stack	a;
    t_stack	b;
 }  t_context;
 
/*assistant functions*/

void	put_error_n_exit(void);
void    *xalloc(size_t count, size_t type_size);
void    free_stack(t_stack *stack);

/* parse */
void parse_args(int argc, char **argv, t_context *context);
void setup_stacks(t_context *context, int *values, int size);

/* sort helpers */
int  stack_is_sorted_asc(t_stack *a); /* ascending: smaller ranks first on top */
void sort_small(t_context *context);                /* handles n<=3..5 safely via dedicated logic */
void sort_three(t_context *context);
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


char	*get_next_line(int fd);
char	*ft_stash_buf_join(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);


# endif
