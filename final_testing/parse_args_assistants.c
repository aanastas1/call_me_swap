/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_assistants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:27:05 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 21:03:49 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	read_value(char **nptr, int *out)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	if (!ft_isdigit(**nptr))
		return (0);
	while (**nptr && !ft_isspace(**nptr))
	{
		if (!ft_isdigit(**nptr))
			return (0);
		res = res * 10 + (**nptr - '0');
		(*nptr)++;
	}
	if (sign * res < INT_MIN || sign * res > INT_MAX)
		return (0);
	*out = (int)(sign * res);
	return (1);
}

static int	push_value(int **out_values, int *cap, int *idx, int value)
{
	if (*idx < *cap)
	{
		(*out_values)[*idx] = value;
		(*idx)++;
		return (1);
	}
	*cap *= 2;
	*out_values = realloc(*out_values, (*cap) * sizeof(**out_values));
	if (!*out_values)
		return (0);
	(*out_values)[*idx] = value;
	(*idx)++;
	return (1);
}

int	parse_one_arg(char *arg, int **out_values, int *capacity, int *idx)
{
	int	value;
	int	added;

	added = 0;
	while (*arg)
	{
		while (*arg && ft_isspace(*arg))
			arg++;
		if (!*arg)
			break ;
		if (!read_value(&arg, &value))
			return (0);
		if (!push_value(out_values, capacity, idx, value))
			return (0);
		added = 1;
	}
	return (added);
}
