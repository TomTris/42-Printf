/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:53:42 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 16:55:46 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx(t_fl *unit, unsigned int n)
{
	char	*to_print;
	int		dot_ori;

	if (n == 0)
		unit->prefix = 0;
	dot_ori = unit->dot;
	if (unit->dot == 0 && unit->flag_0 == 1)
	{
		unit->dot = 1;
		unit->dot_nbr = unit->width;
	}
	if (dot_ori == 0 && n == 0)
	{
		to_print = malloc(2);
		if (to_print == 0)
			return (-1);
		to_print[0] = '0';
		to_print[1] = 0;
	}
	else
		to_print = str_nbr_createx(n, unit);
	return (ft_putx2(unit, to_print, dot_ori));
}
