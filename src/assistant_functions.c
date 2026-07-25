/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 14:42:10 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void *xalloc(size_t count, size_t elem_size)
{
	size_t total;
	void *ptr;

    if (elem_size != 0 && count > SIZE_MAX / elem_size)
       return (NULL); 
    total = count * elem_size;
    ptr = malloc(total);
    return (ptr);
}
int ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int is_number(char *src)
{
	while (ft_isspace(*src))
		src++;
	if (*src == '-' || *src == '+')
		src++;
	if (!*src) /* Check if the string is empty after skipping sign */
		return (0);
	while (*src && !ft_isspace(*src))
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}

static long long	ft_atoill(char **nptr)
{
	int		sign;
	long long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	while (ft_isdigit(**nptr))
	{
		res = res * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (sign * res);
}

int	add_nbr_to_arr(int **out_values, int *capacity, char **nptr, int *idx)
{
	long long	tmp;
	
    if (!is_number(*nptr))
		return (0);
    tmp = ft_atoill(nptr);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	if (*capacity <= *idx)
	{
		*capacity *= 2;
		*out_values = realloc(*out_values, *capacity * sizeof(**out_values));
		if (!*out_values)
			return (0);
	}
	(*out_values)[*idx] = (int)tmp;
	(*idx)++;
	return (1);
}

int	get_number(char *arg, int **out_values, int *capacity, int *idx)
{
	int idx_before;

	idx_before = *idx;
	while (*arg)
	{
		while (*arg && ft_isspace(*arg))
			arg++;
		if (!*arg)
			break;
		if (!add_nbr_to_arr(out_values, capacity, &arg, idx))
			return (0);
	}
	return (*idx - idx_before);
}
