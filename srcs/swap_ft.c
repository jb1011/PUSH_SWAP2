/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:48 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:50 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b(t_util *util)
{
	int	tmp;

	tmp = getAt(util->sta, 0);
	addAt_B(util, tmp, 0);
	freeAt(util, 0);
	util->counter++;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_util *util)
{
	int	tmp;

	tmp = getAt(util->stb, 0);
	addAt(util, tmp, 0);
	freeAt_B(util, 0);
	util->counter++;
	ft_putstr_fd("pa\n", 1);
}

void	rra(t_util *util)
{
	int	pos;
	int	data;

	pos = lenStack(util->sta) - 1;
	data = getAt(util->sta, pos);
	addAt(util, data, 0);
	freeAt(util, (pos + 1));
	util->counter++;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_util *util)
{
	int	pos;
	int	data;

	pos = lenStack(util->stb) - 1;
	data = getAt(util->stb, pos);
	addAt_B(util, data, 0);
	freeAt_B(util, (pos + 1));
	util->counter++;
	ft_putstr_fd("rrb\n", 1);
}

void	ra(t_util *util)
{
	int	data;

	data = getAt(util->sta, 0);
	freeAt(util, 0);
	addnew(util, data);
	util->counter++;
	ft_putstr_fd("ra\n", 1);
}
