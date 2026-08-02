/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 21:58:28 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:25:54 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s);
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	ft_memcpy(buf, s, len + 1);
	return (buf);
}
