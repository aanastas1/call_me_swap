/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:23 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reports whether a character is an ASCII decimal digit. */
static int	is_digit(char character)
{
	return (character >= '0' && character <= '9');
}

/* Reports whether a character is accepted ASCII white space. */
static int	is_space(char character)
{
	return (character == ' ' || (character >= '\t' && character <= '\r'));
}

/* Reads an optional sign and advances the source pointer. */
static int	parse_sign(const char **source)
{
	int	sign;

	sign = 1;
	if (**source == '-' || **source == '+')
	{
		if (**source == '-')
			sign = -1;
		(*source)++;
	}
	return (sign);
}

/* Converts one token while checking syntax and signed int overflow. */
static int	parse_token(const char **source, int *number)
{
	long	value;
	long	limit;
	int		sign;

	sign = parse_sign(source);
	if (!is_digit(**source))
		return (0);
	value = 0;
	limit = INT_MAX;
	if (sign < 0)
		limit = -(long)INT_MIN;
	while (is_digit(**source))
	{
		if (value > (limit - (**source - '0')) / 10)
			return (0);
		value = value * 10 + (**source - '0');
		(*source)++;
	}
	if (**source && !is_space(**source))
		return (0);
	*number = (int)(value * sign);
	return (1);
}

/* Parses every integer token stored inside one argument string. */
int	parse_numbers(const char *source, int *values, int *index)
{
	while (*source)
	{
		while (is_space(*source))
			source++;
		if (!*source)
			break ;
		if (!parse_token(&source, &values[*index]))
			return (0);
		(*index)++;
	}
	return (1);
}
