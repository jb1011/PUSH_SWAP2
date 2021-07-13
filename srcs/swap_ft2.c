/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:54:57 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 13:55:01 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_util *util)
{
	int	pos;
	int	data;

	pos = lenStack(util->stb) - 1;
	data = getAt(util->stb, 0);
	freeAt_B(util, 0);
	addAt_B(util, data, pos);
	util->counter++;
	ft_putstr_fd("rb\n", 1);
}

void	sa(t_util *util)
{
	t_stack	*tmp;

	tmp = createCell(util->sta->next->val);
	freeAt(util, 1);
	addAt(util, tmp->val, 0);
	free(tmp);
	util->counter++;
	ft_putstr_fd("sa\n", 1);
}
