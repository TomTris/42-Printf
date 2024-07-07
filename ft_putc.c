/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:29 by qdo               #+#    #+#             */
/*   Updated: 2024/07/06 21:11:07 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(fl_t *unit, char c)
{
	int	i;

	i = unit->width;
	if (unit->plus == 1)
	{
		while (i-- > 1)
			if (write(1, " ", 1) == -1)
				return (-1);
	}
	if (write(1, &c, 1) < 0)
		return (-1);
	if (unit->plus == 0)
	{
		while (i-- > 1)
			if (write(1, " ", 1) == -1)
				return (-1);
	}
	return (1);
}
