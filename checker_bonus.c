/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:13:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/15 18:39:36 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_all(t_context *context)
{
	if (!context)
		return ;
	free_stack(&context->a);
	free_stack(&context->b);
	ft_memset(context, 0, sizeof(*context));
}

static void	trim_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		s[i] = '\0';
}

static int	op_cmp(t_context *context, char *line)
{
	if (0 == ft_strcmp(line, "sa"))
		return (sa(context), 1);
	else if (0 == ft_strcmp(line, "sb"))
		return (sb(context), 1);
	else if (0 == ft_strcmp(line, "ss"))
		return (ss(context), 1);
	else if (0 == ft_strcmp(line, "pa"))
		return (pa(context), 1);
	else if (0 == ft_strcmp(line, "pb"))
		return (pb(context), 1);
	else if (0 == ft_strcmp(line, "ra"))
		return (ra(context), 1);
	else if (0 == ft_strcmp(line, "rb"))
		return (rb(context), 1);
	else if (0 == ft_strcmp(line, "rr"))
		return (rr(context), 1);
	else if (0 == ft_strcmp(line, "rra"))
		return (rra(context), 1);
	else if (0 == ft_strcmp(line, "rrb"))
		return (rrb(context), 1);
	else if (0 == ft_strcmp(line, "rrr"))
		return (rrr(context), 1);
	else
		return (0);
}

static void	checker(t_context *context)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		trim_line(line);
		if (line[0] == '\0')
		{
			free(line);
			put_error_n_exit();
		}
		if (!op_cmp(context, line))
		{
			free(line);
			put_error_n_exit();
		}
		free(line);
	}
	if (stacks_checker(context))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (0);
	context_init(&context);
	parse_args(argc, argv, &context);
	if (context.a.depth == 0)
	{
		free_all(&context);
		put_error_n_exit();
	}
	checker(&context);
	return (free_all(&context), 0);
}
