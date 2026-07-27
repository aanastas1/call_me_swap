/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:13:33 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/27 21:08:26 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	context_init(t_context *context)
{
	ft_memset(context, 0, sizeof(*context));
}

static void	free_all(t_context *context)
{
	if (!context)
		return;

	free_stack(&context->a);
	free_stack(&context->b);
    ft_memset(context, 0, sizeof(*context));
}

int op_cmp(t_context *context, char *line)
{
    if (ft_strncmp(line, "sa", ft_strlen("sa")) == 0)
        return(sa(&context), 1);
    else if (ft_strncmp(line, "sb", ft_strlen("sb")) == 0)
        return(sb(&context), 1);
    else if (ft_strncmp(line, "ss", ft_strlen("ss")) == 0)
        return(ss(&context), 1);
    else if (ft_strncmp(line, "pa", ft_strlen("pa")) == 0)
        return(pa(&context), 1);
    else if (ft_strncmp(line, "pb", ft_strlen("pb")) == 0)
        return(pb(&context), 1);
    else if (ft_strncmp(line, "ra", ft_strlen("ra")) == 0)
        return(ra(&context), 1);
    else if (ft_strncmp(line, "rb", ft_strlen("rb")) == 0)
        return(rb(&context), 1);
    else if (ft_strncmp(line, "rr", ft_strlen("rr")) == 0)
        return(rr(&context), 1);
    else if (ft_strncmp(line, "rra", ft_strlen("rra")) == 0)
        return(rra(&context), 1);
    else if (ft_strncmp(line, "rrb", ft_strlen("rrb")) == 0)
        return(rrb(&context), 1);
    else if (ft_strncmp(line, "rrr", ft_strlen("rrr")) == 0)
        return(rrr(&context), 1);
    else
        return (0);
}

void checker(t_context *context)
{
    char *line;

    while (1)
    {
        line = get_next_line(0);
            if (!line)
                break;
         if (line[0] == '\0')
        {
            put_error_n_exit();
            return (free(line), 1);
        }
        cut_line() obrezat \n
            if(!op_cmp(context, line))
        {
            put_error_n_exit();
            return(free(line), 1);
         }
        free(line);
    }
    if(stacks_checker(context))
        ft_putstr_fd("OK\n", STDOUT_FILENO);
    else
        ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_context context;
	
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