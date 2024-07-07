/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:15:43 by qdo               #+#    #+#             */
/*   Updated: 2024/07/07 16:56:05 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct fl_s
{
	int	minus;
	int	width;
	int	dot;
	int	dot_nbr;
	int	prefix;
	int	space;
	int	plus;
	int	flag_0;
}	t_fl;

int		ft_atoi(const char *str);
int		ft_printf(const char *str_o, ...);
int		ft_printf2(char *str, int cnt, va_list args);
int		ft_printf3(char *str, int *char_skip, va_list args);

void	unit_init(t_fl *new_unit);
int		ft_decide(char *str, t_fl *unit, int *char_skip, va_list args);
int		dot_nbr_def(char *str, t_fl *unit);
int		wid_def(char *str, t_fl *unit);
int		dot_search(char *str);
void	ft_strncpy(char *src, char *dest, int size);
int		ft_is_man(char *c);
int		ft_exec(char *str, t_fl *unit, va_list args);
int		ft_cmp(char *str, t_fl *unit, va_list args);

int		ft_putp(t_fl *unit, unsigned long n);
int		ft_putc(t_fl *unit, char c);
int		ft_putdi(t_fl *unit, int n);
int		ft_puts(t_fl *unit, char *s);
int		ft_putu(t_fl *unit, unsigned int n);

int		ft_putx(t_fl *unit, unsigned int n);
int		ft_putx2(t_fl *unit, char *to_print, int dot_ori);
char	*str_nbr_createx(unsigned int n, t_fl *unit);

int		ft_putxx(t_fl *unit, unsigned int n);
int		ft_putxx2(t_fl *unit, char *to_print, int dot_ori);
char	*str_nbr_createxx(unsigned int n, t_fl *unit);

char	*ft_strjoin_char(char const *s1, char const s2);
size_t	ft_strlen(const char *a);
char	*ft_strjoin_char_before(char const *s1, char const s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *s1, char *s2);
#endif
