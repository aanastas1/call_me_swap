/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:02:54 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:23:55 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	radix_width(int n)
{
	long	m;
	int		i;

	if (n == 0)
		return (1);
	m = n;
	i = 0;
	if (m < 0)
	{
		m = -m;
		i = 1;
	}
	while (m)
	{
		m /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	m;
	char	*buf;
	int		buf_size;

	buf_size = radix_width(n);
	buf = malloc(buf_size + 1);
	if (!buf)
		return (NULL);
	m = n;
	if (m < 0)
	{
		m = -m;
		buf[0] = '-';
	}
	buf[buf_size] = '\0';
	if (m == 0)
		buf[0] = '0';
	while (m)
	{
		buf_size--;
		buf[buf_size] = m % 10 + '0';
		m /= 10;
	}
	return (buf);
}
