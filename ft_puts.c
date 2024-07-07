/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:51:38 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 17:08:20 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puts2(t_fl *unit, int len, char *str)
{
	char	*space;
	char	*ret;
	int		ret_nbr;

	str[len] = 0;
	space = space_create(str, unit);
	if (space == 0)
		return (-1);
	if (unit->minus == 1)
		ret = ft_strjoin(str, space);
	else
		ret = ft_strjoin(space, str);
	if (ret == 0)
		return (free(str), free(space), -1);
	ret_nbr = write(1, ret, ft_strlen(ret));
	return (free(str), free(space), free(ret), ret_nbr);
}

int	ft_puts(t_fl *unit, char *s)
{
	int		len;
	char	*str;

	if (s != NULL)
	{
		len = ft_strlen(s);
		if (unit->dot == 1 && len > unit->dot_nbr)
			len = unit->dot_nbr;
		str = malloc(len + 1);
		if (str == 0)
			return (-1);
		ft_strncpy(s, str, len);
	}
	else
	{
		len = ft_strlen("(null)");
		if (unit->dot == 1 && len > unit->dot_nbr)
			len = unit->dot_nbr;
		str = malloc(len + 1);
		if (str == 0)
			return (-1);
		ft_strncpy("(null)", str, len);
	}
	return (ft_puts2(unit, len, str));
}
