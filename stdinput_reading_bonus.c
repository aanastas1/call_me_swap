/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:56:11 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/07 19:06:47 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*ft_stash_buf_join(char const *s1, char const *s2)
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

static char	*get_buf(int fd)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(buf), NULL);
	buf[bytes_read] = '\0';
	return (buf);
}

static char	*get_stash(char **stash, int fd)
{
	char	*tmp;
	char	*buf;
	char	*ptr;

	ptr = ft_strchr(*stash, '\n');
	while (!ptr)
	{
		buf = get_buf(fd);
		if (!buf)
			break ;
		tmp = ft_stash_buf_join(*stash, buf);
		free(buf);
		if (!tmp)
			return (NULL);
		free(*stash);
		*stash = tmp;
		ptr = ft_strchr(*stash, '\n');
	}
	return (ptr);
}

static char	*get_op(char **stash, char *ptr)
{
	size_t	len;
	size_t	stash_len;
	char	*op;
	char	*tail;

	stash_len = ft_strlen(*stash);
	if (!ptr)
		len = stash_len;
	else
		len = ptr - *stash + 1;
	op = ft_substr(*stash, 0, len);
	tail = ft_substr(*stash, len, stash_len - len);
	free(*stash);
	*stash = tail;
	return (op);
}

char	*get_operations(int fd)
{
	static char	*stash;
	char		*ptr;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	ptr = get_stash(&stash, fd);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (get_op(&stash, ptr));
}
