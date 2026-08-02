/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:01:46 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:25:16 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*shift;
	unsigned char	value;

	if (n == 0)
		return (s);
	shift = (unsigned char *)s;
	value = (unsigned char)c;
	while (n--)
		*shift++ = value;
	return (s);
}
