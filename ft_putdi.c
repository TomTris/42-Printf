/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:47 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 08:31:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *build(char *temp, char c, int new)
{
	static char *keep;

	if (new == -1)
		return (keep);
	if (new == 1)
	{
		keep = temp;
		return (temp);
	}
	keep = ft_strjoin_char(temp, c);
	free(temp);
	return (keep);
}

static int	ft_write(int n, int cnt)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 10)
		cnt = ft_write(n / 10, cnt + 1);
	if (cnt < 0)
		return (-1);
	n = n % 10;
	a = n + '0';
	if (build(build(0, 0, -1), a, 0) == NULL)
		return (-1);
	return (cnt);
}

char *int_min(fl_t *unit)
{
	char	*ret;

	ret = malloc(12);
	if (ret == 0)
		return (NULL);
	ft_strncpy("-2147483648", ret, 11);
	ret[11] = 0;
	return (ret);
}

int	ft_return(fl_t *unit, int positive)
{
	size_t	len;
	char	*to_print;


	to_print = build(0, 0, -1);
	if (to_print == NULL)
		return (-1);
	len = ft_len(to_print);
	if (unit->width <= len && unit->)
}

int	ft_putdi(fl_t *unit, int n)
{
	int		cnt;
	char	*to_print;
	int		positive;

	cnt = 0;
	if (n == -2147483648)
		to_print = int_min();
	else
	{
		to_print = malloc(1);
		if (to_print == 0)
			return (-1);
		build(to_print, 0, 1);
		if (n < 0)
		{
			positive = -1;
			if (build(to_print, '-', 0) == NULL)
				return (-1);
			n *= -1;
		}
		else
			positive = 1;
	}
	ft_write(n, cnt);
	return (ft_return(unit, positive));
}
