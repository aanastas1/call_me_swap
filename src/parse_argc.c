/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/13 21:50:19 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (1)	
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (!(unsigned char)*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

static long	ft_atoil(const char *nptr)
{
	int	sign;
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

int	all_digits(char *src)
{
	int has_digits = 0;
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

int	is_flag(char *src, t_context *context)
{
	const char *flags[] = {"--simple", "--medium", "--complex", "--adaptive", "--bench", NULL};
	int i;
	int max_index;
	
	i = 0;
	max_index = sizeof(flags) / sizeof(flags[0]) - 1; /* exclude NULL */
	while (flags[i])
	{
		if (ft_strcmp(src, flags[i]) == 0)
		{
			if ((i < max_index - 1) && context->strategy == NONE) /* strategy flags */
				context->strategy = (t_strategy)i;
			else if ((i == max_index - 1) && context->bench_enabled == 0) /* bench flag */
				context->bench_enabled = 1;
			return (1);
		}
		i++;
	}
	return (0);
}


int  parse_args(int argc, char **argv, int **out_values, t_context *context)
{
	int	i;
	int	count;
	long tmp;

	*out_values = malloc(argc * sizeof(**out_values));
	if (!*out_values)
		return (0);
	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i], context))
			continue ;
		else if (all_digits(argv[i]))
		{
			tmp = ft_atoil(argv[i]);
			if (tmp < INT_MIN || tmp > INT_MAX)
				return (0);
			(*out_values)[count++] = tmp;
		}
		else
		{
			return (0);
		}
	}
	return (count);
}
