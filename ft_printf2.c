/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:33:24 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:04:23 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cmp(char *str, t_fl *unit, va_list args)
{
	if (*str == '%')
		return (ft_putc(unit, '%'));
	else if (*str == 'c')
		return (ft_putc(unit, va_arg(args, int)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putdi(unit, va_arg(args, int)));
	else if (*str == 'p')
		return (ft_putp(unit, va_arg(args, unsigned long)));
	else if (*str == 's')
		return (ft_puts(unit, va_arg(args, char *)));
	else if (*str == 'u')
		return (ft_putu(unit, va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_putx(unit, va_arg(args, unsigned long)));
	else if (*str == 'X')
		return (ft_putxx(unit, va_arg(args, unsigned long)));
	else
		return (-1);
}

int	ft_exec(char *str, t_fl *unit, va_list args)
{
	return (ft_cmp(str, unit, args));
}

int	dot_nbr_def(char *str, t_fl *unit)
{
	int		i;
	char	*dot_nbr;

	i = 0;
	while (ft_is_man(str + i) != 1)
		i++;
	dot_nbr = malloc(i + 1);
	if (dot_nbr == 0)
		return (-1);
	ft_strncpy(str, dot_nbr, i);
	dot_nbr[i] = 0;
	unit->dot_nbr = ft_atoi(dot_nbr);
	free(dot_nbr);
	return (1);
}

int	ft_decide2(char **str, t_fl *unit, int *char_skip)
{
	int	i;

	if (dot_search(*str) == 1)
		unit->dot = 1;
	if (ft_is_man(*str) != 1)
	{
		i = 0;
		if (wid_def((*str), unit) == -1)
			return (-1);
		while ((*str)[i] != '.' && ft_is_man((*str) + i) != 1)
			i++;
		if ((*str)[i] == '.')
			i++;
		(*char_skip) += i;
		(*str) += i;
	}
	return (1);
}

int	ft_decide(char *str, t_fl *unit, int *char_skip, va_list args)
{
	int		i;

	if (ft_decide2(&str, unit, char_skip) == -1)
		return (-1);
	if (unit->dot == 1)
	{
		i = 0;
		if (dot_nbr_def(str, unit) == -1)
			return (-1);
		while (ft_is_man(str + i) != 1)
			i++;
		(*char_skip) += i;
		str += i;
	}
	return (ft_exec(str, unit, args));
}
