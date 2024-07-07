/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:23:00 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 12:51:29 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n(unsigned long n)
{
	if (n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static char	*str_nbr_create(unsigned long n)
{
	char	*ret;
	char	*temp;

	if (n == 0)
	{
		ret = malloc(2);
		if (ret == 0)
			return (0);
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

static char	*str_zero_space_sign_add(char *ret, t_fl *unit, unsigned long n)
{
	char	*temp;

	(void) n;
	(void) unit;
	temp = ret;
	ret = ft_strjoin_char_before(ret, 'x');
	free(temp);
	if (ret == 0)
		return (ret);
	temp = ret;
	ret = ft_strjoin_char_before(ret, '0');
	free(temp);
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

int	ft_putp(t_fl *unit, unsigned long n)
{
	char	*to_print;
	char	*space;
	char	*ret;
	int		ret_nbr;

	to_print = str_nbr_create(n);
	if (to_print == 0)
		return (-1);
	to_print = str_zero_space_sign_add(to_print, unit, n);
	space = space_create(to_print, unit);
	if (unit->minus == 1)
		ret = ft_strjoin(to_print, space);
	else
		ret = ft_strjoin(space, to_print);
	free(to_print);
	free(space);
	ret_nbr = write(1, ret, ft_strlen(ret));
	free(ret);
	return (ret_nbr);
}
