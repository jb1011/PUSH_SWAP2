/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:02:34 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:02:36 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	test_int_max(char **argv, int *tab, int i, int j)
{
	char	*str;

	tab[i] = ft_atoi(argv[j]);
	str = ft_itoa(tab[i]);
	if (ft_strncmp(argv[j], str, ft_strlen(argv[j])) != 0)
	{
		ft_putstr_fd("Error\n", 0);
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

void	init_list(t_util *util)
{
	util->sta = NULL;
	util->stb = NULL;
}

void	addAt(t_util *util, int data, int pos)
{
	t_stack	*prec;
	t_stack	*current;
	t_stack	*cell;

	cell = createCell(data);
	prec = util->sta;
	current = util->sta;
	if (is_empty(util->sta))
	{
		util->sta = cell;
		return ;
	}
	if (pos == 0)
	{
		cell->next = util->sta;
		util->sta = cell;
		return ;
	}
	addAt2(cell, prec, pos, current);
}

void	addAt2(t_stack *cell, t_stack *prec, int pos, t_stack *current)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		i++;
		prec = current;
		current = current->next;
	}
	prec->next = cell;
	cell->next = current;
}
