/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:26 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:00:55 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_nbr_create(unsigned int n)
{
	char	*ret;
	char	*temp;

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

static char	*str_zero_space_sign_add(char *ret, t_fl *unit)
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
	if (unit->plus == 1 || unit->space == 1)
	{
		temp = ret;
		if (unit->plus == 1)
			ret = ft_strjoin_char_before(ret, '+');
		else
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
		return (free(ret), NULL);
	space[0] = 0;
	while (i++ < unit->width)
	{
		temp = space;
		space = ft_strjoin_char_before(space, ' ');
		free(temp);
		if (space == 0)
			return (free(ret), NULL);
	}
	return (space);
}

int	ft_putu2(char *to_print, t_fl *unit)
{
	char	*space;
	char	*ret;
	int		ret_nbr;

	if (to_print == 0)
		return (-1);
	to_print = str_zero_space_sign_add(to_print, unit);
	space = space_create(to_print, unit);
	if (unit->minus == 1)
		ret = ft_strjoin(to_print, space);
	else
		ret = ft_strjoin(space, to_print);
	if (ret == 0)
		return (free(to_print), free(space), -1);
	ret_nbr = write(1, ret, ft_strlen(ret));
	return (free(to_print), free(space), free(ret), ret_nbr);
}

int	ft_putu(t_fl *unit, unsigned int n)
{
	char	*to_print;
	int		dot_ori;

	dot_ori = unit->dot;
	if (unit->dot == 0 && unit->flag_0 == 1)
	{
		unit->dot = 1;
		unit->dot_nbr = unit->width;
		if (unit->plus == 1 || unit->space == 1)
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
		to_print = str_nbr_create(n);
	return (ft_putu2(to_print, unit));
}
