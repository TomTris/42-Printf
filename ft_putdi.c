/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:47 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:18:11 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_nbr_create(int n, char *ret, char *temp)
{
	if (n == -2147483648)
	{
		ret = malloc(11);
		if (ret == 0)
			return (NULL);
		ft_strncpy("2147483648", ret, 11);
		return (ret[10] = 0, ret);
	}
	if (n < 0)
		n *= -1;
	ret = malloc(1);
	if (ret == 0)
		return (NULL);
	ret[0] = 0;
	while (n != 0)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, (n % 10) + '0');
		free(temp);
		if (ret == 0)
			return (NULL);
		n = n / 10;
	}
	return (ret);
}

static char	*str_zero_space_sign_add(char *ret, t_fl *unit, int n)
{
	char	*temp;
	int		cnt;

	cnt = (int) ft_strlen(ret);
	while (cnt++ < unit->dot_nbr)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, '0');
		free(temp);
		if (ret == 0)
			return (NULL);
	}
	if (n < 0 || unit->plus == 1 || unit->space == 1)
	{
		temp = ret;
		if (n < 0)
			ret = ft_strjoin_char_before(ret, '-');
		else if (unit->plus == 1)
			ret = ft_strjoin_char_before(ret, '+');
		else if (unit->space == 1)
			ret = ft_strjoin_char_before(ret, ' ');
		free(temp);
	}
	return (ret);
}

static char	*space_create(char *ret, t_fl *unit)
{
	int		i;
	char	*space;
	char	*temp;

	i = (int) ft_strlen(ret);
	space = malloc(1);
	if (space == 0)
		return (NULL);
	space[0] = 0;
	while (i++ < unit->width)
	{
		temp = space;
		space = ft_strjoin_char_before(space, ' ');
		free(temp);
		if (space == 0)
			return (NULL);
	}
	return (space);
}

int	ft_putdi2(char *to_print, t_fl *unit, int n)
{
	char	*space;
	char	*ret;

	if (to_print == 0)
		return (-1);
	to_print = str_zero_space_sign_add(to_print, unit, n);
	if (to_print != 0)
		space = space_create(to_print, unit);
	if (to_print == 0 || space == 0)
		return (free(to_print), -1);
	if (unit->minus == 1)
		ret = ft_strjoin(to_print, space);
	else
		ret = ft_strjoin(space, to_print);
	free(to_print);
	free(space);
	if (ret == 0)
		return (-1);
	n = write(1, ret, ft_strlen(ret));
	return (free(ret), n);
}

int	ft_putdi(t_fl *unit, int n)
{
	char	*to_print;
	int		dot_ori;

	dot_ori = unit->dot;
	if (unit->dot == 0 && unit->flag_0 == 1)
	{
		unit->dot = 1;
		unit->dot_nbr = unit->width;
		if (n < 0 || unit->plus == 1 || unit->space == 1)
			unit->dot_nbr -= 1;
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
		to_print = str_nbr_create(n, 0, 0);
	return (ft_putdi2(to_print, unit, n));
}
