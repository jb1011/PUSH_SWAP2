/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksBig2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:37:05 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/19 11:37:08 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_big_5(t_util *util)
{
	while (still_chunk(util, util->chunk8, util->chunk9))
	{
		ft_scan(util, util->chunk8, util->chunk9);
		ft_move_chunks(util);
		if (is_bigger(util) == 1)
			sort_b(util->stb, util);
		else
			put_closemintop(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk9, util->chunk10))
	{
		ft_scan(util, util->chunk9, util->chunk10);
		ft_move_chunks(util);
		if (is_bigger(util) == 1)
			sort_b(util->stb, util);
		else
			put_closemintop(util);
		push_b(util);
		util->len--;
	}
	parse_big_6(util);
}

void	parse_big_6(t_util *util)
{
	while (still_chunk(util, util->chunk10, util->max))
	{
		ft_scan(util, util->chunk10, util->max);
		ft_move_chunks(util);
		if (is_bigger(util) == 1)
			sort_b(util->stb, util);
		else
			put_closemintop(util);
		push_b(util);
		util->len--;
	}
	while (is_empty(util->stb) != 1)
	{
		sort_b(util->stb, util);
		push_a(util);
	}
}
