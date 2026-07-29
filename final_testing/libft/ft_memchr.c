/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:47:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:28:32 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_bytes;

	s_bytes = (unsigned char *)s;
	while (n--)
	{
		if (*s_bytes == (unsigned char)c)
			return ((void *)s_bytes);
		s_bytes++;
	}
	return (NULL);
}
