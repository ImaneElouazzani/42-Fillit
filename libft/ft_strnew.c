/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:46:14 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/04 06:47:18 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
