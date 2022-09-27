/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:29:21 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/22 17:07:23 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_convdata
{
	int minusflag;
	int zeroflag;
	int width;
	int prec;
}					t_convdata;

int					ft_printf(const char *src, ...);
struct s_convdata	ft_data_ini();
int					ft_check(char c, char *str);
struct s_convdata	ft_balec(char c, t_convdata dat);
int					ft_searchprecwi(const char *str, int *i);
int					ft_writezero(int prec, int i);
int					ft_zerofunct(t_convdata dat);
int					ft_isnegative(long *nb);
long				ft_writenbr(long nb, long divider);
int					ft_code_x(va_list *list, t_convdata dat);
int					ft_code_ux(va_list *list, t_convdata dat);
int					ft_code_pour(va_list *list, t_convdata dat);
int					ft_code_s(va_list *list, t_convdata dat);
int					ft_code_c(va_list *list, t_convdata dat);
int					ft_code_di(va_list *list, t_convdata dat);
int					ft_code_u(va_list *list, t_convdata dat);
int					ft_code_p(va_list *list, t_convdata dat);
int					ft_putchar(const char c);
struct s_convdata	ft_convdata(const char *str, int *i);
struct s_convdata	ft_precwi(va_list *list, t_convdata dat);
int					ft_widthmaker(int i, int widthval, t_convdata dat);
int					ft_minusflag(int i, int width);
int					ft_code_di(va_list *list, t_convdata dat);
int					ft_code_u(va_list *list, t_convdata dat);
int					ft_code_p(va_list *list, t_convdata dat);
int					ft_code_s(va_list *list, t_convdata dat);
int					ft_code_x(va_list *list, t_convdata dat);
int					ft_code_ux(va_list *list, t_convdata dat);
int					ft_code_c(va_list *list, t_convdata dat);
int					ft_code_pour(va_list *list, t_convdata dat);
int					ft_putnbr(long num, t_convdata dat);
int					ft_putstr(char *s, t_convdata dat);
int					ft_putstr2(char *s, t_convdata dat);
int					ft_putstr3(char *s, int len, t_convdata dat);
char				*ft_itoa_base(unsigned long num, char *base);
void				ft_rev(char *tab, int size);
int					ft_atoi(char *str);
unsigned long		ft_strlen(char *str);

#endif
