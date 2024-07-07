/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:23:31 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 13:27:14 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf3(char *str, int *char_skip, va_list args)
{
	t_fl	unit;

	unit_init(&unit);
	if (ft_is_man(str) == 0)
	{
		while (*str == ' ')
		{
			unit.space = 1;
			str++;
			(*char_skip)++;
		}
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

// int	main(void)
// {
// 	// char *a = "";

// 	printf("{%d}\n", printf("%-2.c", '0'));
// 	printf("{%d}\n", ft_printf("%-2.c", '0'));
// 	// printf("% d\n", 0);
// }