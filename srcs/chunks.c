/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:17 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:20 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_chunks(t_stack *sta, t_util *util)
{
	util->max = ft_find_biggest(sta);
	util->chunk1 = util->max / 4;
	util->chunk2 = util->chunk1 * 2;
	util->chunk3 = util->chunk1 * 3;
	util->len = (lenStack(sta));
}

void	ft_scan(t_util *util, int min, int max)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	util->index1 = -1;
	util->index2 = -1;
	tmp = util->sta;
	if (util->len % 2 == 0)
		util->mid = (util->len / 2) - 1;
	else
		util->mid = (util->len / 2);
	while (i < util->mid)
	{
		if (tmp->val >= min && tmp->val <= max)
		{
			util->index1 = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	util->save = i;
	ft_scan2(util, min, max, tmp);
}

void	ft_scan2(t_util *util, int min, int max, t_stack *tmp)
{
	int	j;

	while (util->save < util->mid)
	{
		util->save++;
		tmp = tmp->next;
	}
	j = 0;
	while (util->save < util->len)
	{
		if (tmp->val >= min && tmp->val <= max)
		{
			if (util->len % 2 == 0)
				util->index2 = util->mid - j + 2;
			else
				util->index2 = util->mid - j + 1;
		}
		tmp = tmp->next;
		j++;
		util->save++;
	}
}

void	ft_move_chunks(t_util *util)
{
	int	i;

	i = 0;
	if (util->index1 != -1 && util->index2 == -1)
	{
		while (i < util->index1)
		{
			ra(util);
			util->counter++;
			i++;
		}
	}
	if (util->index2 != -1 && util->index1 == -1)
	{
		while (i < util->index2)
		{
			rra(util);
			util->counter++;
			i++;
		}
	}
	ft_move_chunks2(util, i);
}

void	ft_move_chunks2(t_util *util, int i)
{
	if (util->index1 <= util->index2 && util->index1 != -1)
	{
		while (i < util->index1)
		{
			ra(util);
			util->counter++;
			i++;
		}
	}
	if (util->index1 > util->index2 && util->index2 != -1)
	{
		while (i < util->index2)
		{
			rra(util);
			util->counter++;
			i++;
		}
	}
}
