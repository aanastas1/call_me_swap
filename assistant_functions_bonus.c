/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:44:41 by aloiko            #+#    #+#             */
/*   Updated: 2026/08/07 16:54:10 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	*xalloc(size_t count, size_t elem_size)
{
	size_t	total;
	void	*ptr;

	if (elem_size != 0 && count > SIZE_MAX / elem_size)
		return (NULL);
	total = count * elem_size;
	ptr = malloc(total);
	return (ptr);
}

void	put_error_n_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	context_init(t_context *context)
{
	ft_memset(context, 0, sizeof(*context));
}
