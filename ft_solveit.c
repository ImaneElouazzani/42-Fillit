/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solveit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:41:17 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/20 19:56:07 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solveit(t_fillit *fillit, int *num, t_tetris *head)
{
	int		size;

	size = 0;
	size = ft_init_size(num[0]);
	ft_gentab(fillit, size);
	ft_backtracking(head, fillit, size);
	ft_printtab(fillit->starting_tab);
	ft_freelst(head);
	ft_freedouble(fillit->starting_tab);
	free(fillit);
}
