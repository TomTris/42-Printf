/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:29:20 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 10:27:33 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *s1, char *s2)
{
	char	*a;

	a = s1;
	while (*s2)
		*a++ = *s2++;
	return (s1);
}

size_t	ft_strlen(const char *a)
{
	int		cnt;
	char	*b;

	cnt = 0;
	b = (char *)a;
	while (*b != '\0')
	{
		b++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin_char(char const *s1, char const s2)
{
	size_t	s1_len;
	char	*ret;

	s1_len = ft_strlen((char *)s1);
	ret = (char *)malloc((s1_len + 1 + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	ft_strcpy(ret, (char *)s1);
	ret[ft_strlen(s1)] = s2;
	ret[ft_strlen(s1) + 1] = 0;
	return (ret);
}

char	*ft_strjoin_char_before(char const *s1, char const s2)
{
	size_t	s1_len;
	char	*ret;

	s1_len = ft_strlen((char *)s1);
	ret = (char *)malloc((s1_len + 1 + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	ft_strcpy(ret + 1, (char *)s1);
	ret[0] = s2;
	ret[ft_strlen(s1) + 1] = 0;
	return (ret);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (sign * nbr);
}
