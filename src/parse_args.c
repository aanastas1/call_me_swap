/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 17:22:44 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

typedef enum e_mode
{
    unknown,
    single_numbers,
    complex_arg
}   t_mode;

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static double	compute_disorder_values(const int *values, int n)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total_pairs++;
			if (values[i] > values[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
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

static int fill_the_buffer(int max_args, char *arg, int **out_values, int *size)
{
	static t_mode	mode;

	if (has_spaces(arg))
	{
		if (mode == single_numbers || mode == complex_arg)
				return (0);
		*size = complex_string_split(out_values, arg);
		mode = complex_arg;
	}
	else 
	{
		if (mode == complex_arg)
			return (0);
		if(!*out_values)
			*out_values = xalloc(max_args, sizeof(**out_values));
		if (!add_nbr_to_arr(out_values, arg, *size))
			return (0);
		(*size)++;
		if (mode == unknown)          // проверяем, в каком режиме мы сейчас находимся
    		mode = single_numbers;    // если был «unknown», переключаемся в режим single_numbers
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_context *context)
{
	int		*out_values;
	int		count;
	int		i;
	
	out_values = NULL;
	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_strategy_flag(argv[i], context))
			continue ;
		if (!fill_the_buffer(argc, argv[i], &out_values, &count))
				return (free(out_values));
	}
	if (!validate_no_dups(out_values, count))
		return (free(out_values));
	setup_stacks(context, out_values, count);
	context->disorder = compute_disorder_values(out_values, count);
	free(out_values);
}
