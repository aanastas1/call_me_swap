/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 18:37:46 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

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
	if (n < 2)
		return 0;
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
	//printf("DEBUG: total_pairs %d, %d\n", total_pairs, (n * (n - 1) / 2));
	return ((double)mistakes / (double)total_pairs);
}

static int	is_strategy_flag(char *src, t_context *context)
{
	const char	*flags[] = {"--bench", "--simple", "--medium", "--complex", "--adaptive"};
	int	i;
	int	max_index;

	i = 0;
	max_index = sizeof(flags) / sizeof(flags[0]) - 1; 
	while (i <= max_index)
	{
		if (ft_strcmp(src, flags[i]) == 0)
		{
			if (i == 0 && context->bench_enabled == 0) /* bench flag */
				context->bench_enabled = 1;
			else if (!context->strategy) /* strategy flags */
				context->strategy = (t_strategy)i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int fill_the_buffer(char *arg, int **out_values, int *capacity, int *idx)
{
	int count;
	 
	count = get_number(arg, out_values, capacity, idx);
	return (count);
}

void	parse_args(int argc, char **argv, t_context *context)
{
	int		*out_values;
	int		count;
	int		size;
	int		capacity;
	int		i;
	int		idx;
	
	capacity = argc;
	out_values = xalloc(capacity, sizeof(*out_values));
	if (!out_values)
		put_error_n_exit();
	idx = 0;
	count = 0;
	size = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_strategy_flag(argv[i], context))
			continue ;
		else
		{
			count = fill_the_buffer(argv[i], &out_values, &capacity, &idx);
				if (!count)
				{
					free(out_values);
					return ;
				}
			size += count;
		}
	}
	setup_stacks(context, out_values, size);
	context->disorder = compute_disorder_values(out_values, size);
	free(out_values);
}
