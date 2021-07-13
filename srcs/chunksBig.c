/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksBig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:33:51 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:33:53 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_chunks_big(t_stack *sta, t_util *util)
{
	util->max = ft_find_biggest(sta);
	util->chunk1 = util->max / 11;
	util->chunk2 = util->chunk1 * 2;
	util->chunk3 = util->chunk1 * 3;
	util->chunk4 = util->chunk1 * 4;
	util->chunk5 = util->chunk1 * 5;
	util->chunk6 = util->chunk1 * 6;
	util->chunk7 = util->chunk1 * 7;
	util->chunk8 = util->chunk1 * 8;
	util->chunk9 = util->chunk1 * 9;
	util->chunk10 = util->chunk1 * 10;
	util->len = (lenStack(sta));
}

void	parse_big(t_util *util)
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
	parse_big_2(util);
}

void	parse_big_2(t_util *util)
{
	while (still_chunk(util, util->chunk3, util->chunk4))
	{
		ft_scan(util, util->chunk3, util->chunk4);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk4, util->chunk5))
	{
		ft_scan(util, util->chunk4, util->chunk5);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk5, util->chunk6))
	{
		ft_scan(util, util->chunk5, util->chunk6);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	parse_big_3(util);
}

void	parse_big_3(t_util *util)
{
	while (still_chunk(util, util->chunk6, util->chunk7))
	{
		ft_scan(util, util->chunk6, util->chunk7);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk7, util->chunk8))
	{
		ft_scan(util, util->chunk7, util->chunk8);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk8, util->chunk9))
	{
		ft_scan(util, util->chunk8, util->chunk9);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	parse_big_4(util);
}

void	parse_big_4(t_util *util)
{
	while (still_chunk(util, util->chunk9, util->chunk10))
	{
		ft_scan(util, util->chunk9, util->chunk10);
		ft_move_chunks(util);
		push_b(util);
		util->len--;
	}
	while (still_chunk(util, util->chunk10, util->max))
	{
		ft_scan(util, util->chunk10, util->max);
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
