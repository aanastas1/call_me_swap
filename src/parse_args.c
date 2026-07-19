/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/18 15:56:48 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void *xalloc(size_t count, size_t elem_size)
{
	size_t total;

    if (elem_size != 0 && count > SIZE_MAX / elem_size)
        put_error_n_exit(); 
    total = count * elem_size;
    void *p = malloc(total);
    if (!p)
        put_error_n_exit();
    return p;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static long	ft_atoil(const char *nptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}

int	is_number(char *src)
{
	int	has_digits;

	has_digits = 0;
	if (*src == '-' || *src == '+')
		src++;
	if (!*src) /* Check if the string is empty after skipping sign */
		return (0);
	while (*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		has_digits = 1;
		src++;
	}
	return (has_digits);
}

static int	is_strategy_flag(char *src, t_context *context)
{
	const char	*flags[] = {"--simple", "--medium", "--complex", "--adaptive", "--bench"};
	int	i;
	int	max_index;

	i = 0;
	max_index = sizeof(flags) / sizeof(flags[0]) - 1; /* last index is for --bench */
	while (i <= max_index)
	{
		if (ft_strcmp(src, flags[i]) == 0)
		{
			if ((i < max_index - 1) && !context->strategy) /* strategy flags */
				context->strategy = (t_strategy)i;
			else if ((i == max_index) && context->bench_enabled == 0) /* bench flag */
				context->bench_enabled = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
int has_spaces(char *src)
{
	while (*src)
	{
		if (ft_isspace(*src))
			return (1);
		src++;
	}
	return (0);
}
int	find_buf_size(char **buf)
{
	int	i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}
int out_of_int_range(long nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	return (0);
}

int	add_nbr_to_arr(int **out_values, char *nptr, int idx)
{
	long	tmp;

	tmp = ft_atoil(nptr);
	if (out_of_int_range(tmp))
			return (0);
	(*out_values)[idx] = (int)tmp;
	return (1);
}

void free_split(char **buf)
{
    int i;

    if (!buf)
        return ;
    i = 0;
    while (buf[i])
    {
        free(buf[i]);
        i++;
    }
    free(buf);
}

int complex_string_split(int **out_values, char *str)
{
	char	**buf;
	int		buf_size;
	const char c = ' ';
	int	i;
			
	buf = ft_split(str, c);
	if (!buf)
		return (0); /*add return error NULL if no buf*/
	buf_size = find_buf_size(buf);
	*out_values = xalloc(buf_size, sizeof(**out_values));
	i = 0;
	while (i < buf_size)
	{ 
		if (!is_number(buf[i]))
			return (0);
		if (!add_nbr_to_arr(out_values, buf[i], i))
			return (0);
		i++;
	}
	free_split(buf);
	return (buf_size);
}

void	parse_args(int argc, char **argv, t_context *context)
{
	enum e_mode {unknown, single_numbers, spaced_arg};
	enum e_mode	mode;
	int		*out_values;
	int		i;
	int		count;
	
	/*printf("DEBUG: parse_args start\n");*/
	out_values = NULL;
	count = 0;
	mode = unknown;
	i = 0;
	while (++i < argc)
	{
		if (is_strategy_flag(argv[i], context))
			continue ;
		else if (has_spaces(argv[i]))
		{
			if (mode == single_numbers || mode == spaced_arg)
				return ;
			count = complex_string_split(&out_values, argv[i]);
			mode = spaced_arg;
		}
		else 
		{
			if (mode == spaced_arg || !is_number(argv[i]))
				return ;
			if(!out_values)
				out_values = xalloc(argc, sizeof(*out_values));
			if (!add_nbr_to_arr(&out_values, argv[i], count))
				return ;
			count++;
			mode = (mode == unknown) ? single_numbers : mode;
		}
	}
	if (!validate_no_dups(out_values, count))
			return ;
	setup_stacks(context, out_values, count);
	context->disorder = compute_disorder_values(out_values, count);
	free(out_values);
}
