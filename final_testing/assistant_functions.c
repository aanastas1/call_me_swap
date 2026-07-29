/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:49 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/29 21:25:00 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("Error", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

void	put_operation(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	free_stack(t_stack *stack)
{
	t_node		*curr;
	t_node		*next;
	int			i;
	int			depth;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	depth = stack->depth;
	i = 0;
	while (i < depth)
	{
		next = curr->next;
		free(curr);
		curr = next;
		i++;
	}
	stack->top = NULL;
	stack->depth = 0;
}
