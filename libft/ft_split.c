/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:36:41 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/18 16:36:43 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(char const *s, char c)
{
	int		counter;
	int		is_word;

	is_word = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static size_t	wid(char const *s, int pos, char c)
{
	size_t	len;

	len = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (len);
		len++;
		pos++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (k == 0)
				tab[j] = (char *)malloc(sizeof(char) * wid(s, i, c) + 1);
			tab[j][k] = s[i];
			tab[j][++k] = '\0';
		}
		k = 0;
		if ((s[i] == c && s[i + 1] != c && k > 0))
			j++;
	}
	tab[ft_count(s, c)] = NULL;
	return (tab);
}
