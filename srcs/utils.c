/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:00 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:04 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*createCell(int data)
{
	t_stack	*cell;

	cell = malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->val = data;
	cell->next = NULL;
	return (cell);
}

void	addnew(t_util *util, int data)
{
	t_stack	*cell;
	t_stack	*tmp;

	cell = createCell(data);
	if (is_empty(util->sta))
	{
		util->sta = cell;
		return ;
	}
	tmp = util->sta;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = cell;
}

void	addnew_b(t_util *util, int data)
{
	t_stack	*cell;
	t_stack	*tmp;

	cell = createCell(data);
	if (is_empty(util->stb))
	{
		util->stb = cell;
		return ;
	}
	tmp = util->stb;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = cell;
}

void	addAt_B(t_util *util, int data, int pos)
{
	t_stack	*prec;
	t_stack	*current;
	t_stack	*cell;

	cell = createCell(data);
	prec = util->stb;
	current = util->stb;
	if (is_empty(util->stb))
	{
		util->stb = cell;
		return ;
	}
	if (pos == 0)
	{
		cell->next = util->stb;
		util->stb = cell;
		return ;
	}
	addAt_B2(cell, prec, pos, current);
}

void	addAt_B2(t_stack *cell, t_stack *prec, int pos, t_stack *current)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		i++;
		prec = current;
		current = current->next;
	}
	prec->next = cell;
	cell->next = current;
}
