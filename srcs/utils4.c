/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:02:34 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/02 15:02:36 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	test_int_max(char **argv, int *tab, int i, int j)
{
	tab[i] = ft_atoi(argv[j]);
	if (ft_strncmp(argv[j], ft_itoa(tab[i]), ft_strlen(argv[j])) != 0)
	{
		ft_putstr_fd("Error\n", 0);
		return (0);
	}
	return (1);
}
