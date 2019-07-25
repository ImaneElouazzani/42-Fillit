/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:18:27 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/08 23:58:39 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Get the number of digits in a string
*/

static int	ft_strdig(const char *str)
{
	int digits;

	digits = 0;
	while (IS_DIG(*str))
	{
		digits++;
		str++;
	}
	return (digits);
}

int			ft_atoi(const char *str)
{
	int neg;
	int integ;

	integ = 0;
	while (IS_BL(*str))
		str++;
	neg = (*str == '-') ? 1 : 0;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	if (ft_strdig(str) > 18)
		return ((neg == 1) ? 0 : -1);
	if (ft_strdig(str) == 18 && ft_strcmp(str, "9223372036854775807") > 0)
		return ((neg == 1) ? 0 : -1);
	while (*str != '\0')
	{
		if (IS_DIG(*str))
		{
			integ *= 10;
			integ += (int)*str - 48;
		}
		else
			break ;
		str++;
	}
	return ((neg == 1) ? -integ : integ);
}
