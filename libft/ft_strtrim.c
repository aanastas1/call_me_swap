/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:49:20 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:26:45 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_bitmask(char const *set, unsigned char *bitmask, size_t size)
{
	unsigned char	c;
	char const		*s;

	ft_memset(bitmask, 0, size);
	s = set;
	while (*s)
	{
		c = (unsigned char)*s;
		bitmask[c >> 3] |= (1 << (c & 7));
		s++;
	}
}

static int	check_in_set(char c, unsigned char *bitmask)
{
	return (bitmask[(unsigned char)c >> 3] & (1 << ((unsigned char)c & 7)));
}

static const char	*begin(char const *str, unsigned char *bitmask)
{
	char const	*s;

	s = str;
	while (*str && check_in_set(*s, bitmask))
		s++;
	return (s);
}

static const char	*final(char const *str, unsigned char *bitmask)
{
	char const	*s;
	size_t		len;

	len = ft_strlen(str);
	s = &str[len - 1];
	while (len > 0 && check_in_set(*s, bitmask))
	{
		s--;
		len--;
	}
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char		*start;
	const char		*end;
	unsigned char	bitmask[32];
	char			*buf;
	size_t			buf_size;

	if (!s1 || !set)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	set_bitmask(set, bitmask, sizeof(bitmask));
	start = begin(s1, bitmask);
	end = final(s1, bitmask);
	if (end < start)
		return (ft_strdup(""));
	buf_size = end - start + 1;
	buf = malloc(buf_size + 1);
	if (!buf)
		return (NULL);
	ft_memcpy(buf, start, buf_size);
	buf[buf_size] = '\0';
	return (buf);
}
