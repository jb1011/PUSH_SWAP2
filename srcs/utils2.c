/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:26:08 by jdemenet          #+#    #+#             */
/*   Updated: 2021/06/22 12:26:11 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	freeList(t_util *util)
{
	t_stack	*tmp;
	t_stack	*to_delete;

	tmp = util->sta;
	if (!is_empty(tmp))
	{
		while (tmp)
		{
			to_delete = tmp;
			tmp = tmp->next;
			free(to_delete);
		}
	}
	util->sta = NULL;
	tmp = util->stb;
	if (!is_empty(tmp))
	{
		while (tmp)
		{
			to_delete = tmp;
			tmp = tmp->next;
			free(to_delete);
		}
	}
	util->stb = NULL;
}

int	lenStack(t_stack *st)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = st;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	freeAt(t_util *util, int pos)
{
	t_stack	*prec;
	t_stack	*current;
	int		i;

	prec = util->sta;
	current = util->sta;
	if (is_empty(util->sta))
		return ;
	if (pos == 0)
	{
		util->sta = util->sta->next;
		free(current);
		return ;
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = current;
		current = current->next;
	}
	prec->next = current->next;
	free (current);
}

void	freeAt_B(t_util *util, int pos)
{
	t_stack	*prec;
	t_stack	*current;
	int		i;

	prec = util->stb;
	current = util->stb;
	if (is_empty(util->stb))
		return ;
	if (pos == 0)
	{
		util->stb = util->stb->next;
		free(current);
		return ;
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = current;
		current = current->next;
	}
	prec->next = current->next;
	free (current);
}

void	initStack(t_util *util, char *argv)
{
	int	arg;

	arg = ft_atoi(argv);
	addnew(util, arg);
}
