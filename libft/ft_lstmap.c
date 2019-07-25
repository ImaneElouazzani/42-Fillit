/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:48:18 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/08 23:50:29 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *mem, size_t size)
{
	(void)size;
	free(mem);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *mylist;

	if (lst == NULL)
		return (NULL);
	head = f(lst);
	mylist = head;
	while (lst->next)
	{
		lst = lst->next;
		if ((head->next = f(lst)) == NULL)
		{
			ft_lstdel(&mylist, ft_del);
			return (NULL);
		}
		head = head->next;
	}
	return (mylist);
}
