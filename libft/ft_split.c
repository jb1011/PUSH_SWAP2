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

// size_t	ft_count(char const *s, char c)
// {
// 	int		counter;
// 	int		is_word;

// 	is_word = 0;
// 	counter = 0;
// 	while (*s)
// 	{
// 		if (*s == c)
// 			is_word = 0;
// 		else if (is_word == 0)
// 		{
// 			is_word = 1;
// 			counter++;
// 		}
// 		s++;
// 	}
// 	return (counter);
// }

// static size_t	wid(char const *s, int pos, char c)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[pos])
// 	{
// 		if (s[pos] == c)
// 			return (len);
// 		len++;
// 		pos++;
// 	}
// 	return (len);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = -1;
// 	j = 0;
// 	k = 0;
// 	tab = malloc(sizeof(char *) * (ft_count(s, c) + 1));
// 	while (s[++i])
// 	{
// 		if (s[i] != c)
// 		{
// 			if (k == 0)
// 				tab[j] = (char *)malloc(sizeof(char) * wid(s, i, c) + 1);
// 			tab[j][k] = s[i];
// 			tab[j][++k] = '\0';
// 		}
// 		k = 0;
// 		if ((s[i] == c && s[i + 1] != c && k > 0))
// 			j++;
// 	}
// 	tab[ft_count(s, c)] = NULL;
// 	return (tab);
// }

static char			**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}