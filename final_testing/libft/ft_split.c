/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:20:29 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:25:43 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (c == *s)
			s++;
		else
		{
			while (*s && c != *s)
				s++;
			count++;
		}
	}
	return (count);
}

static void	free_buf(char **buf, size_t count)
{
	while (count >= 1)
	{
		count--;
		free(buf[count]);
	}
	free(buf);
}

static size_t	get_word_length(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static void	fill_buf(char **buf, char const *s, char c, size_t buf_size)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = get_word_length(&s[i], c);
			buf[count] = malloc(j + 1);
			if (!buf[count])
			{
				free_buf(buf, count);
				return ;
			}
			buf[count] = ft_memcpy(buf[count], &s[i], j);
			buf[count++][j] = '\0';
			i += j;
		}
	}
	buf[buf_size] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	buf_size;
	char	**buf;

	if (!s)
		return (NULL);
	if (!*s)
	{
		buf = malloc(sizeof(char *));
		if (!buf)
			return (NULL);
		else
		{
			buf[0] = NULL;
			return (buf);
		}
	}
	buf_size = count_words(s, c);
	buf = malloc((buf_size + 1) * sizeof(char *));
	if (!buf)
		return (NULL);
	fill_buf(buf, s, c, buf_size);
	return (buf);
}
