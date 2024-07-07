/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:03:37 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:09:12 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n(unsigned int n)
{
	if (n <= 9)
		return (n + '0');
	return (n + 'A' - 10);
}

char	*str_nbr_createxx(unsigned int n, t_fl *unit)
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

static char	*str_zero_space_sign_add(char *ret, t_fl *unit,
		int dot_ori, int cnt)
{
	char	*temp;

	cnt = (int) ft_strlen(ret);
	if (unit->prefix == 1 && dot_ori != 1)
		cnt += 2;
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

int	ft_putxx2(t_fl *unit, char *to_print, int dot_ori)
{
	int		ret_nbr;
	char	*ret;
	char	*space;

	if (to_print == 0)
		return (-1);
	to_print = str_zero_space_sign_add(to_print, unit, dot_ori, 0);
	if (to_print != 0)
		space = space_create(to_print, unit);
	if (to_print == 0 || space == 0)
		return (free(to_print), -1);
	if (unit->minus == 1)
		ret = ft_strjoin(to_print, space);
	else
		ret = ft_strjoin(space, to_print);
	if (ret == 0)
		return (free(to_print), free(space), -1);
	ret_nbr = write(1, ret, ft_strlen(ret));
	return (free(to_print), free(space), free(ret), ret_nbr);
}
