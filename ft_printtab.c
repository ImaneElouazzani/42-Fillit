/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:27:32 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/20 18:58:12 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printtab(char **tetris)
{
	int		i;
	int		j;

	i = 0;
	while (tetris[i])
	{
		j = 0;
		while (tetris[i][j])
		{
			ft_putchar(tetris[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
