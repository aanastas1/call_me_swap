/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:57:19 by aloiko            #+#    #+#             */
/*   Updated: 2026/06/30 17:24:42 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*add_list_back(t_list **head, t_list **tail, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		return (NULL);
	if (*head == NULL)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
	return (*head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	void	*content;

	head = NULL;
	tail = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		if (content)
		{
			if (!add_list_back(&head, &tail, content))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
		}
		lst = lst->next;
	}
	return (head);
}
