/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:45:36 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:50 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reports whether a character is accepted ASCII white space. */
static int	is_white_space(char character)
{
	return (character == ' ' || (character >= '\t' && character <= '\r'));
}

/* Compares two strings and returns their first byte difference. */
int	ft_strcmp(const char *first, const char *second)
{
	while (*first && *first == *second)
	{
		first++;
		second++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}

/* Counts white-space-separated tokens in one argument string. */
int	count_words(const char *source)
{
	int	count;

	count = 0;
	while (*source)
	{
		while (is_white_space(*source))
			source++;
		if (!*source)
			break ;
		count++;
		while (*source && !is_white_space(*source))
			source++;
	}
	return (count);
}
