/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:29 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 15:31:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("--{%c}\n", d);
int	ft_putc2(t_fl *unit, int cnt, int i)
{
	if (unit->minus != 0)
	{
		while (i-- > 1)
		{
			if (write(1, " ", 1) == -1)
				return (-1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_putc(t_fl *unit, char d)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = unit->width;
	if (unit->minus == 0)
	{
		while (i-- > 1)
		{
			if (write(1, " ", 1) == -1)
				return (-1);
			cnt++;
		}
	}
	if (write(1, &d, 1) < 0)
		return (-1);
	cnt++;
	return (ft_putc2(unit, cnt, i));
}
