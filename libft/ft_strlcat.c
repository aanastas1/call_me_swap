/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:32:13 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:26:07 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (dst_len + ft_strlen(src));
	while (*src && dst_len < size - 1)
		dst[dst_len++] = *src++;
	dst[dst_len] = '\0';
	return (dst_len + ft_strlen(src));
}
