/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:39 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:42 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp->next != NULL)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_a_sorted(t_util *util)
{
	t_stack	*tmp;

	tmp = util->sta;
	while (tmp->next != NULL)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_very_small(t_util *util)
{
	int	max;
	int	min;

	max = ft_find_biggest(util->sta);
	min = ft_find_small(util->sta, util);
	if (util->sta->val == max && !is_sorted(util->sta))
	{
		ra(util);
		if (!is_sorted(util->sta))
			sa(util);
	}
	else if (util->sta->val != min && util->sta->val != max)
	{
		sa(util);
		if (!is_sorted(util->sta))
		{
			ra(util);
			sa(util);
		}
	}
	else if (util->sta->val == min)
	{
		sa(util);
		ra(util);
	}
}

int	ft_find_small(t_stack *st, t_util *util)
{
	int		min;
	t_stack	*tmp;

	min = 214483447;
	tmp = st;
	util->small = 0;
	while (tmp)
	{
		if (min > tmp->val)
			min = tmp->val;
		tmp = tmp->next;
	}
	tmp = st;
	while (tmp)
	{
		if (tmp->val == min)
			break ;
		util->small++;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_small(t_util *util)
{
	int	min;

	while (!is_a_sorted(util))
	{
		min = ft_find_small(util->sta, util);
		if (util->sta->val == min)
			push_b(util);
		if (util->small > lenStack(util->sta) / 2)
			rra(util);
		else
			ra(util);
	}
	while (util->stb)
		push_a(util);
}
