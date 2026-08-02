/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:42:44 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:26:03 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	char	*buf_start;

	if (!s1 || !s2)
		return (NULL);
	buf = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buf)
		return (NULL);
	buf_start = buf;
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (buf_start);
}
