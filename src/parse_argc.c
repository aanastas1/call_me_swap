/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:09:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/12 16:46:01 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoil(const char *nptr)
{
	int	sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
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

int	is_digits(char *src)
{
	if (*src == '-' || *src == '+')
		src++;
	while (*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}

int	is_flag(char *src)
{
	const char *flags[] = {"--simple", "--medium", "--complex", "--adaptive", "--bench", NULL};
	while (*flags)
	{
		if (ft_strcmp(*flags, src) == 0)
		{
			return (1);
		}
		flags++;
	}	
	return (0);
}

int  parse_args(int argc, char **argv, int **out_values)
{
	int	i;
	int	count;
	long tmp;

	*out_values = malloc(argc * sizeof(**out_values));
	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			continue ;
		else if (is_digits(argv[i]))
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
