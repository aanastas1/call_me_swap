/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:13:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 20:53:04 by aloiko           ###   ########.fr       */
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

int	op_cmp(t_context *context, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (sa(context), 1);
	else if (ft_strcmp(line, "sb") == 0)
		return (sb(context), 1);
	else if (ft_strcmp(line, "ss") == 0)
		return (ss(context), 1);
	else if (ft_strcmp(line, "pa") == 0)
		return (pa(context), 1);
	else if (ft_strcmp(line, "pb") == 0)
		return (pb(context), 1);
	else if (ft_strcmp(line, "ra") == 0)
		return (ra(context), 1);
	else if (ft_strcmp(line, "rb") == 0)
		return (rb(context), 1);
	else if (ft_strcmp(line, "rr") == 0)
		return (rr(context), 1);
	else if (ft_strcmp(line, "rra") == 0)
		return (rra(context), 1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (rrb(context), 1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (rrr(context), 1);
	else
		return (0);
}

void	checker(t_context *context)
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
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc < 2)
		return (1);
	context_init(&context);
	parse_args(argc, argv, &context);
	if (context.a.depth == 0)
	{
		free_all(&context);
		put_error_n_exit();
	}
	checker(&context);
	free_all(&context);
	return (0);
}
