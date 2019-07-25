/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:51:36 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/08 23:53:21 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *mylist;

	if ((mylist = malloc(sizeof(*mylist))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	else
	{
		mylist->content = malloc(sizeof(*content) * content_size);
		ft_strcpy(mylist->content, content);
		mylist->content_size = content_size;
	}
	mylist->next = NULL;
	return (mylist);
}
