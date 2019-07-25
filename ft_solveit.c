/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solveit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:41:17 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/25 20:52:50 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solveit(int *num, t_tetris *head, int fd)
{
	int			size;
	t_fillit	*fillit;

	if ((fillit = malloc(sizeof(t_fillit))) == NULL)
		return ;
	fillit->starting_tab = NULL;
	size = ft_init_size(*num);
	ft_gentab(fillit, size);
	ft_backtracking(head, fillit, size);
	ft_printtab(fillit->starting_tab);
	ft_freelst(head);
	ft_freedouble(fillit->starting_tab);
	free(fillit);
	close(fd);
}
