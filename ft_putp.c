/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:23:00 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 11:48:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n(unsigned long n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static char	*str_nbr_create(unsigned int n)
{
	char	*ret;

	ret = malloc(1);
	if (ret == 0)
		return (NULL);
	ret[0] = 0;
	while (n != 0)
	{
		ret = ft_strjoin_char_before(ret, ft_n(n % 16));
		if (ret == 0)
			return (NULL);
		n = n / 10;
	}
	return (ret);
}

static char	*str_zero_space_sign_add(char *ret, fl_t *unit, unsigned int n)
{
	char	*temp;
	int		cnt;

	temp = ret;
	ret = n
	return (ret);
}

static char	*space_create(char *ret, fl_t *unit)
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

int	ft_putp(fl_t *unit, unsigned int n)
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
	return (n);
}
