/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:36:27 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/19 17:54:05 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

typedef struct s_context
{
	t_stack	a;
	t_stack	b;
}	t_context;

/*assistant functions*/
void	put_error_n_exit(void);
void	*xalloc(size_t count, size_t type_size);
void	free_stack(t_stack *stack);
int		stacks_checker(t_context *context);
int		ft_strcmp(const char *s1, const char *s2);
void	context_init(t_context *context);
char	*get_next_line(int fd);

/* parse */
void	parse_args(int argc, char **argv, t_context *context);
void	setup_stacks(t_context *context, int *values, int size);

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

#endif
