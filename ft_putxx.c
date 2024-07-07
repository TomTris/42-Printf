/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:03:37 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 15:28:06 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n(unsigned int n)
{
	if (n <= 9)
		return (n + '0');
	return (n + 'A' - 10);
}

static char	*str_nbr_create(unsigned int n, t_fl *unit)
{
	char	*ret;
	char	*temp;

	if (n == 0 && unit->dot == 0)
	{
		ret = malloc(2);
		if (ret == 0)
			return (NULL);
		return (ret[0] = '0', ret[1] = 0, ret);
	}
	ret = malloc(1);
	if (ret == 0)
		return (NULL);
	ret[0] = 0;
	while (n != 0)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, ft_n(n % 16));
		free(temp);
		if (ret == 0)
			return (NULL);
		n = n / 16;
	}
	return (ret);
}

static char	*str_zero_space_sign_add(char *ret, t_fl *unit, unsigned int n)
{
	char	*temp;
	int		cnt;

	(void) n;
	cnt = (int) ft_strlen(ret);
	while (cnt++ < unit->dot_nbr)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, '0');
		free(temp);
		if (ret == 0)
			return (NULL);
	}
	if (unit->prefix == 1)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, 'X');
		free(temp);
		if (ret == 0)
			return (ret);
		temp = ret;
		ret = ft_strjoin_char_before(ret, '0');
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

int	ft_putxx(t_fl *unit, unsigned int n)
{
	char	*to_print;
	char	*space;
	char	*ret;
	int		ret_nbr;

	if (n == 0)
		unit->prefix = 0;
	if (unit->dot == 0 && unit->flag_0 == 1)
	{
		unit->dot = 1;
		unit->dot_nbr = unit->width;
		if (unit->plus == 1 || unit->space == 1)
			unit->dot_nbr -= 1;
	}
	to_print = str_nbr_create(n, unit);
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
	ret_nbr = write(1, ret, ft_strlen(ret));
	return (free(to_print), free(space), free(ret), ret_nbr);
}
