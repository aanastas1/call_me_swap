/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:56:11 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/28 18:35:43 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char *get_buf(int fd)
{
    char    *buf;
    ssize_t bytes_read;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(buf);
        return (NULL);
    }
    buf[bytes_read] = '\0';
    return (buf);
}

static char	*get_stash(char **stash, int fd)
{
	char	*tmp;
	char	*buf;
	char 	*ptr;

	if (!*stash)
	{
		*stash = malloc(1);
		*stash[0] = '\0';
	}
	ptr = NULL;
	while (1)
    {
		buf = get_buf(fd);
		if (!buf)
			break ;
		tmp = ft_stash_buf_join(*stash, buf);
		free(*stash);
		free(buf);
		*stash = tmp;
		ptr = ft_strchr(*stash, '\n');
		if (ptr)
			break ;
	}
	return (ptr);
}

static char	*get_line(char **stash, char *ptr)
{
	size_t	len;
	char	*line;
	char	*tail;

    len = ptr - *stash + 1; // include newline
    line = ft_substr(*stash, 0, len);
    tail = ft_substr(*stash, len, ft_strlen(*stash) - len);
    free(*stash);
    *stash = tail;
	return (line);
}

char *get_next_line(int fd)
{
    static char *stash;
    char	*ptr;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
	{
        if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	ptr = get_stash(&stash, fd);
    if (!stash || !*stash)
    {
        free(stash);
        stash = NULL;
		ptr = NULL;
        return (NULL);
    }
	if (!ptr)
		ptr = ft_strchr(stash, '\n');
	line = get_line(&stash, ptr);
    return (line);
}

