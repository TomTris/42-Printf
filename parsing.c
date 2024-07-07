/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:35:22 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 14:17:48 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_man(char *c)
{
	if (*c == 'c' || *c == 'p' || *c == 's' || *c == 'd' || *c == 'i'
		|| *c == 'u' || *c == 'x' || *c == 'X' || *c == '%')
		return (1);
	return (0);
}

void	ft_strncpy(char *src, char *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	dot_search(char *str)
{
	while (ft_is_man(str) != 1)
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}

int	wid_def(char *str, t_fl *unit)
{
	int		i;
	char	*width;

	i = 0;
	while (str[i] != '.' && ft_is_man(str + i) != 1)
		i++;
	width = malloc(i + 1);
	if (width == 0)
		return (-1);
	ft_strncpy(str, width, i);
	width[i] = 0;
	unit->width = ft_atoi(width);
	free(width);
	return (1);
}

void	unit_init(t_fl *new_unit)
{
	new_unit->minus = 0;
	new_unit->width = 0;
	new_unit->dot = 0;
	new_unit->dot_nbr = 0;
	new_unit->prefix = 0;
	new_unit->space = 0;
	new_unit->plus = 0;
	new_unit->flag_0 = 0;
}
