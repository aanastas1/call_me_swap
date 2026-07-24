/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_string_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:17:31 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/24 21:47:32 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
/*
static void free_split(char **buf)
{
    int i;

    if (!buf)
        return ;
    i = 0;
    while (buf[i])
    {
        free(buf[i]);
        i++;
    }
    free(buf);
}

static int	find_buf_size(char **buf)
{
	int	i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}

int complex_string_split(int **out_values, char *str)
{
	char	**buf;
	int		buf_size;
	const char c = ' ';
	int	i;
			
	buf = ft_split(str, c);
	if (!buf)
		put_error_n_exit(); 
	buf_size = find_buf_size(buf);
	*out_values = xalloc(buf_size, sizeof(**out_values));
	i = 0;
	while (i < buf_size)
	{ 
		if (!add_nbr_to_arr(out_values, buf[i], i))
			return (free_split(buf), 0);
		i++;
	}
	free_split(buf);
	return (buf_size);
}*/
