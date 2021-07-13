/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:24:38 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:27:05 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	getAt(t_stack *st, int pos)
{
	int	i;

	i = 0;
	if (is_empty(st))
	{
		ft_putstr_fd("liste vide\n", 0);
		return (-1);
	}
	while (i < pos)
	{
		i++;
		st = st->next;
	}
	return (st->val);
}

int	ft_find_biggest(t_stack *sta)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = sta;
	while (tmp)
	{
		if (max < tmp->val)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

int	test_argv(char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				ft_putstr_fd("Error\n", 0);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	is_empty(t_stack *st)
{
	if (st == NULL)
		return (1);
	return (0);
}

void	printStack(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp)
	{
		ft_putnbr_fd(tmp->val, 0);
		ft_putchar_fd(' ', 0);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 0);
}
