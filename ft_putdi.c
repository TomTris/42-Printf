/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:47 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 11:00:46 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//unit here to define dot_nbr
char	*str_nbr_create(int n)
{
	char	*ret;

	if (n == -2147483648)
	{
		ret = malloc(11);
		if (ret == 0)
			return (-1);
		ft_strncpy("2147483648", ret, 11);
		ret[10] = 0;
	}
	else if (n == 0)
	{
		ret = malloc(2);
		if (ret == 0)
			return (-1);
		ret[0] = '0';
		ret[1] = 0;
	}
	else
	{
		ret = malloc(1);
		if (ret == 0)
			return (NULL);
		ret[0] = 0;
		while (n != 0)
		{
			ret = ft_strjoin_char_before(ret, (n % 10) + '0');
			if (ret == 0)
				return (NULL);
			n = n / 10;
		}
	}
	return (ret);
}

char	*str_zero_space_sign_add(char *ret, fl_t *unit, int n)
{
	int		cnt;
	char	*temp;

	cnt = (int) ft_strlen(ret);
	if (n < 0 || unit->plus == 1 || unit->space == 1)
		cnt++;
	while (cnt++ < unit->dot_nbr)
	{
		temp = ret;
		ret = ft_strjoin_char_before(ret, '0');
		free(temp);
		if (ret == 0)
			return (-1);
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
		if (ret == 0)
			return (-1);
	}	
	return (ret);
}

int	space_cnt(char *ret, fl_t *unit)
{
	int		i;
	char	*space;
	char	*temp;

	i = (int) ft_strlen(ret);
	space = malloc(1);
	if (space == 0)
		return (free(ret), -1);
	space[0] = 0;
	while (i++ < unit->width)
	{
		temp = space;
		space = ft_strjoin_char_before(space, ' ');
		free(temp);
		if (space == 0)
			return (free(ret), -1);
	}
	return (space);
}

int	ft_putdi(fl_t *unit, int n)
{
	char	*to_print;
	char	*space;
	char	*ret;

	to_print = str_nbr_create(n);
	if (to_print == 0)
		return (-1);
	to_print = str_zero_space_sign_add(to_print, unit, n);
	space = space_cnt(to_print, unit);
	if (unit->minus == 1)
		ret = ft_strjoin(to_print, space);
	else
		ret = ft_strjoin(space, to_print);
	free(to_print);
	free(space);
	n = write(1, ret, ft_strlen(ret));
	free(ret);
	return (n);
}
