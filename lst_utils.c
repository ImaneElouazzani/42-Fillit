/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:49:06 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/21 17:28:50 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_tetris *head)
{
	t_tetris	*temp;

	while (head != NULL)
	{
		temp = head->next;
		if (head->cords)
			free(head->cords);
		free(head);
		head = temp;
	}
}
