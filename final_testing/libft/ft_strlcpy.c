/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:12:21 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:26:11 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		n;
	const char	*s;
	char		*d;

	n = size;
	s = src;
	d = dst;
	if (n)
	{
		while (--n)
		{
			*d++ = *s++;
			if (!*(s - 1))
				break ;
		}
	}
	if (!n)
	{
		if (size)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
