/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:15:43 by qdo               #+#    #+#             */
/*   Updated: 2024/07/06 21:44:31 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct fl_s
{
	int	minus;
	int	width;
	int	dot;
	int	dot_nbr;
	int	prefix;
	int	space;
	int	plus;
} fl_t;

int	ft_atoi(const char *str);

void	unit_init(fl_t *new_unit);
int		ft_decide(char *str, fl_t *unit, int *char_skip, va_list args);
int		dot_nbr_def(char *str, fl_t *unit);
int		wid_def(char *str, fl_t *unit);
int		dot_search(char *str);
void	ft_strncpy(char *src, char *dest, int size);
int		ft_is_man(char *c);
int		ft_exec(char *str, fl_t *unit, va_list args);
int		ft_cmp(char *str, fl_t *unit, va_list args);

int		ft_putp(fl_t *unit, unsigned long n);
int		ft_putc(fl_t *unit, char c);
int		ft_putdi(fl_t *unit, int n);
int		ft_puts(fl_t *unit, char *s);
int		ft_putu(fl_t *unit, unsigned int n);
int		ft_putx(fl_t *unit, unsigned int n);
int		ft_putxx(fl_t *unit, unsigned int n);
char	*ft_strjoin_char(char const *s1, char const s2);
size_t	ft_strlen(const char *a);
#endif
