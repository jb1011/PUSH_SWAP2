/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:03:11 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:03:14 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	test_double(char **argv, int argc)
{
	int	i;
	int	j;
	int	tab[10000];

	j = 0;
	i = -1;
	while (++i < argc - 1)
		if (test_int_max(argv, tab, i, ++j) == 0)
			return (0);
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (tab[i] == tab[j] && j != i)
			{
				ft_putstr_fd("Error\n", 0);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_check_double_arg(int	*arr, int count, t_util *util)
{
	int	i;
	int	j;

	i = 0;
	util->lenstack = count;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (arr[i] == arr[j] && j != i)
			{
				ft_putstr_fd("Error\n", 0);
				return ;
			}
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < count)
		addnew(util, arr[i]);
	util->go = 1;
}

void	ft_parse_arg(char **argv, t_util *util)
{
	int		i;
	int		j;
	char	**tab;
	int		arr[10000];

	j = -1;
	util->go = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[++j])
	{
		i = -1;
		while (tab[j][++i])
		{
			if (tab[j][i] < '0' || tab[j][i] > '9')
			{
				ft_putstr_fd("Error\n", 0);
				return ;
			}
		}
		if (test_int_max(tab, arr, j, j) == 0)
			return ;
		free(tab[j]);
	}
	free(tab);
	ft_check_double_arg(arr, j, util);
}

int	main(int argc, char **argv)
{
	t_util	util;
	int		i;

	i = 0;
	init_list(&util);
	if (argc > 1)
	{
		if (ft_strchr(argv[1], ' '))
			ft_parse_arg(argv, &util);
		else
		{
			util.lenstack = argc - 1;
			util.go = 1;
			if (test_double(argv, argc) && test_argv(argv, argc))
				while (++i < argc)
					initStack(&util, argv[i]);
			else
			{
				freeList(&util);
				return (0);
			}
		}
		ft_main_sequel(&util);
	}
}

void	ft_main_sequel(t_util *util)
{
	util->counter = 0;
	if (util->go == 1)
	{
		if (!is_sorted(util->sta) && util->lenstack == 3)
			sort_very_small(util);
		if (!is_sorted(util->sta) && util->lenstack > 3 && util->lenstack <= 8)
			sort_small(util);
		if (!is_sorted(util->sta) && util->lenstack > 8 && util->lenstack < 400)
		{
			ft_set_chunks(util->sta, util);
			parse_medium(util);
		}
		if (!is_sorted(util->sta) && util->lenstack >= 400)
		{
			ft_set_chunks_big(util->sta, util);
			parse_big(util);
		}
	}
	freeList(util);
}
