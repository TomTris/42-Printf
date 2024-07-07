/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:23:31 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:06:05 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf3(char *str, int *char_skip, va_list args)
{
	t_fl	unit;

	unit_init(&unit);
	while (*str == '#' || *str == '+' || *str == '-' || *str == '0'
		|| *str == ' ')
	{
		if (*str == '#')
			unit.prefix = 1;
		else if (*str == '+')
			unit.plus = 1;
		else if (*str == '-')
			unit.minus = 1;
		else if (*str == ' ')
			unit.space = 1;
		else if (*str == '0')
			unit.flag_0 = 1;
		(*char_skip)++;
		(str)++;
	}
	return (ft_decide(str, &unit, char_skip, args));
}

int	ft_printf2(char *str, int cnt, va_list args)
{
	int	char_skip;
	int	check;

	while (*str)
	{
		while (*str && (*str) != '%')
		{
			if (write(1, str, 1) == -1)
				return (-1);
			str++;
			cnt++;
		}
		if (*str == '%')
		{
			str++;
			char_skip = 0;
			check = ft_printf3(str, &char_skip, args);
			if (check < 0)
				return (-1);
			cnt += check;
			str += char_skip;
			str++;
		}
	}
	return (cnt);
}

int	ft_printf(const char *str_o, ...)
{
	va_list	args;
	char	*str;
	int		cnt;

	cnt = 0;
	str = (char *)str_o;
	va_start(args, str_o);
	cnt = ft_printf2(str, cnt, args);
	va_end(args);
	return (cnt);
}
