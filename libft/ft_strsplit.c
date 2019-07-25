/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:32:50 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/11 00:12:12 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char const *str, char c)
{
	int count;
	int is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (IS_DEL(*str))
		{
			(void)(is_word && count++);
			is_word = 0;
		}
		else
			is_word = 1;
		str++;
	}
	(void)(is_word && count++);
	return (count);
}

static int		cnt_ch(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && !IS_DEL(s[i]))
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(res = malloc(sizeof(char*) * (countwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (IS_DEL(s[i]) && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(res[j] = malloc(sizeof(char) * cnt_ch(s + i, c) + 1)))
				return (NULL);
			while (!IS_DEL(s[i]) && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
