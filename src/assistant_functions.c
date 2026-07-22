/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/22 17:46:38 by aloiko           ###   ########.fr       */
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

int has_spaces(char *src)
{
	while (*src)
	{
		if (*src == ' ' || (*src >= '\t' && *src <= '\r'))
			return (1);
		src++;
	}
	return (0);
}

static int	is_number(char *src)
{
	int	is_number;

	is_number = 1;
	if (*src == '-' || *src == '+')
		src++;
	if (!*src) /* Check if the string is empty after skipping sign */
		return (0);
	while (*src)
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (is_number);
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

int	add_nbr_to_arr(int **out_values, char *nptr, int idx)
{
	long	tmp;

    if (!is_number(nptr))
    {
        return (0);
    }
    tmp = ft_atoil(nptr);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	(*out_values)[idx] = (int)tmp;
	return (1);
}