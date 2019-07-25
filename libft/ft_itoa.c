/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:57:56 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/09 00:40:12 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Get the number of digits in an int, sign included
*/

static int		intlen(int n)
{
	int digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char			*ft_itoa(int n)
{
	int		digits;
	char	*str;
	int		i;
	long	num;

	num = n;
	i = 0;
	digits = intlen(num);
	if ((str = malloc(sizeof(*str) * (digits + 1))) == NULL)
		return (NULL);
	str[digits--] = '\0';
	if (num < 0)
	{
		str[i++] = '-';
		num *= -1;
	}
	while (i <= digits)
	{
		str[digits] = (char)(num % 10) + 48;
		num /= 10;
		digits--;
	}
	return (str);
}
