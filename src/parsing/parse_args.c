/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 11:36:22 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_index(char *src)
{
	const char	*flags[] = {"--simple", "--medium", "--complex",
		"--adaptive", "--bench"};
	int			index;

	index = 0;
	while (index < 5)
	{
		if (ft_strcmp(src, flags[index]) == 0)
			return (index);
		index++;
	}
	return (-1);
}

static int	set_flag(char *src, t_context *context)
{
	int	index;

	index = flag_index(src);
	if (index < 0)
		return (0);
	if (index == 4)
	{
		if (context->bench_enabled)
			return (-1);
		context->bench_enabled = 1;
	}
	else
	{
		if (context->strategy != NONE)
			return (-1);
		context->strategy = (t_strategy)index;
	}
	return (1);
}

static int	count_input(int argc, char **argv, t_context *context)
{
	int	index;
	int	flag;
	int	count;
	int	words;

	index = 1;
	count = 0;
	while (index < argc)
	{
		flag = set_flag(argv[index], context);
		if (flag < 0)
			return (0);
		if (flag == 0)
		{
			words = count_words(argv[index]);
			if (words == 0 || count > INT_MAX - words)
				return (0);
			count += words;
		}
		index++;
	}
	return (count);
}

int	parse_args(int argc, char **argv, int **out_values, t_context *context)
{
	int	arg_index;
	int	value_index;
	int	count;

	*out_values = NULL;
	count = count_input(argc, argv, context);
	if (count < 1)
		return (0);
	*out_values = malloc(sizeof(**out_values) * count);
	if (!*out_values)
		return (0);
	arg_index = 1;
	value_index = 0;
	while (arg_index < argc)
	{
		if (flag_index(argv[arg_index]) < 0
			&& !parse_numbers(argv[arg_index], *out_values, &value_index))
			return (0);
		arg_index++;
	}
	return (count);
}
