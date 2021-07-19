/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:27 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:32 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_smallest(t_stack *sta, t_util *util)
{
	int		min;
	t_stack	*tmp;

	min = -1;
	util->i = 0;
	tmp = sta;
	while (tmp)
	{
		if (min < tmp->val)
			min = tmp->val;
		tmp = tmp->next;
	}
	tmp = sta;
	while (tmp)
	{
		if (min == tmp->val)
			break ;
		util->i++;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_b(t_stack *stb, t_util *util)
{
	int	len;
	int	i;
	int	nbr;

	len = lenStack(stb);
	i = 0;
	ft_find_smallest(stb, util);
	if (util->i > len / 2)
	{
		nbr = len - util->i;
		while (i < nbr)
		{
			rrb(util);
			i++;
		}
	}
	else
	{
		while (i < util->i)
		{
			rb(util);
			i++;
		}
	}
}

int	is_bigger(t_util *util)
{
	int		max;

	max = ft_find_biggest(util->stb);
	if (util->sta->val > max)
		return (1);
	return (0);
}

void	put_closemintop(t_util *util)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	ft_find_closest(util->stb, util);
	len = lenStack(util->stb);
	if (util->close > len / 2)
	{
		nbr = len - util->close;
		while (i < nbr)
		{
			rrb(util);
			i++;
		}
	}
	else
	{
		while (i < util->close)
		{
			rb(util);
			i++;
		}
	}
}

int	ft_find_closest(t_stack *sta, t_util *util)
{
	int		search;
	t_stack	*tmp;
	int		i;

	search = util->sta->val;
	util->close = 0;
	i = 0;
	tmp = sta;
	while (tmp)
	{
		if (tmp->val < search && i < tmp->val)
			i = tmp->val;
		tmp = tmp->next;
	}
	tmp = sta;
	while (tmp)
	{
		if (i == tmp->val)
			break ;
		util->close++;
		tmp = tmp->next;
	}
	return (i);
}
