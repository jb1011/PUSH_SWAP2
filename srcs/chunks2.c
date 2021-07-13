/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:16:01 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 14:17:27 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	still_chunk(t_util *util, int min, int max)
{
	t_stack	*tmp;

	tmp = util->sta;
	while (tmp)
	{
		if (tmp->val >= min && tmp->val <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	parse_medium(t_util *util)
{
	while (still_chunk(util, 0, util->chunk1))
	{
		ft_scan(util, 0, util->chunk1);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk1, util->chunk2))
	{
		ft_scan(util, util->chunk1, util->chunk2);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk2, util->chunk3))
	{
		ft_scan(util, util->chunk2, util->chunk3);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	parse_medium2(util);
}

void	parse_medium2(t_util *util)
{
	while (still_chunk(util, util->chunk3, util->max))
	{
		ft_scan(util, util->chunk3, util->max);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (is_empty(util->stb) != 1)
	{
		sort_b(util->stb, util);
		push_a(util);
	}
}
