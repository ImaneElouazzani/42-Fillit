/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:14:55 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/21 13:33:33 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_links(char *str)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 0 && str[i - 1] == '#')
				links++;
			if (i < 19 && str[i + 1] == '#')
				links++;
			if (i < 14 && str[i + 5] == '#')
				links++;
			if (i > 4 && str[i - 5] == '#')
				links++;
		}
		i++;
	}
	if (links != 6 && links != 8)
		return (0);
	return (1);
}

int		ft_is_format_valid(char *str)
{
	int		i;
	int		hashtags;
	int		points;

	i = 0;
	hashtags = 0;
	points = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '#')
			hashtags++;
		if (str[i] == '.')
			points++;
		i++;
	}
	if (hashtags != 4 || points != 12)
		return (0);
	return (1);
}

int		ft_check_format(char *str, t_tetris *head, char letter, int *num_tetris)
{
	if (ft_is_format_valid(str) == 0 || ft_links(str) == 0)
		return (0);
	ft_getcord(str, head);
	head->letter = letter;
	num_tetris[0]++;
	return (1);
}
