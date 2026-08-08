/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:10:07 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/07 19:14:02 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	char	*base;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	base = buf;
	while (len--)
		*buf++ = s[start++];
	*buf = '\0';
	return (base);
}
