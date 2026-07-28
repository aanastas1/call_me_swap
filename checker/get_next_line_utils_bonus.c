/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:10:07 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 18:35:49 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_stash_buf_join(char const *s1, char const *s2)
{
	char	*buf;
	char	*buf_start;

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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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


size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}
/*
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
}*/
