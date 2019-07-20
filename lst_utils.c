/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:49:06 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/20 19:32:12 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_tetris *head)
{
	t_tetris	*temp;
	int			j;

	while (head != NULL)
	{
		j = 0;
		temp = head->next;
		if (head->cords)
			free(head->cords);
		free(head);
		head = temp;
	}
}
