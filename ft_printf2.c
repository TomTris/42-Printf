/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:33:24 by qdo               #+#    #+#             */
/*   Updated: 2024/07/06 20:42:55 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_cmp(char *str, va_list args)
// {
// 	if (*str == '%')
// 		return (ft_putc('%'));
// 	else if (*str == 'c')
// 		return (ft_putc(va_arg(args, int)));
// 	else if (*str == 'p')
// 		return (ft_putp(va_arg(args, unsigned long)));
// 	else if (*str == 's')
// 		return (ft_puts(va_arg(args, char *)));
// 	else if (*str == 'd' || *str == 'i')
// 		return (ft_putdi(va_arg(args, int)));
// 	else if (*str == 'u')
// 		return (ft_putu(va_arg(args, unsigned int)));
// 	else if (*str == 'x')
// 		return (ft_putx(va_arg(args, unsigned int)));
// 	else if (*str == 'X')
// 		return (ft_putxx(va_arg(args, unsigned int)));
// 	else
// 		return (-1);
// }

int	ft_exec(char *str, fl_t *unit, va_list args)
{
	(void) str;
	(void) args;
	(void) unit;
	return (1);
}

int	dot_nbr_def(char *str, fl_t *unit)
{
	int	i;
	char	*dot_nbr;

	unit->dot = 1;
	i = 0;
	while (ft_is_man(str + i) != 1)
		i++;
	dot_nbr = malloc(i + 1);
	if (dot_nbr == 0)
		return (-1);
	ft_strncpy(str, dot_nbr, i);
	unit->dot_nbr = ft_atoi(dot_nbr);
	free(dot_nbr);
	return (1);
}

int	ft_decide(char *str, fl_t *unit, int *char_skip, va_list args)
{
	int		i;

	while (*str == '#' || *str == '+' || *str == '-')
	{
		if (*str == '#')
			unit->prefix = 1;
		if (*str == '+')
			unit->plus = 1;
		if (*str == '-')
			unit->minus = 1;
		(*char_skip)++;
		str++;
	}
	if (dot_search(str) == 1)
	{
		i = 0;
		if (wid_def(str, unit) == -1)
			return (-1);
		while (str[i] != '.')
			i++;
		(*char_skip) += i + 1;
		str += i + 1;
	}
	if (ft_is_man(str) != 1)
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
