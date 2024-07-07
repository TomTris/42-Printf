/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:16:53 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 10:30:43 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*a;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	a = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (a == 0)
		return (NULL);
	ft_strcpy(a, (char *)s1);
	ft_strcpy((a + s1_len), (char *)s2);
	*(a + s1_len + s2_len) = 0;
	return (a);
}
