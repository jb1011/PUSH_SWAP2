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
