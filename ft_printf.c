/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:23:31 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 11:47:54 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf3(char *str, int *char_skip, va_list args)
{
	fl_t unit;

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
			cnt++;
			char_skip = 0;
			if (ft_printf3(str, &char_skip, args) < 0)
				return (-1);
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

int	main(void)
{
	// ft_printf("%%", 0);
	char a;

	printf("%+p\n", &a);
}