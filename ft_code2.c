/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:16:16 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:51:27 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_code_x(va_list *list, t_convdata dat)
{
	unsigned int	num;
	int				i;
	char			*str;

	dat = ft_precwi(list, dat);
	num = va_arg(*list, unsigned int);
	str = ft_itoa_base(num, "0123456789abcdef");
	ft_rev(str, ft_strlen(str));
	if (str[0] == '0' && dat.prec == 0)
	{
		str = "";
		dat.zeroflag = 0;
	}
	i = ft_putstr3(str, ft_strlen(str), dat);
	return (i);
}

int					ft_code_ux(va_list *list, t_convdata dat)
{
	unsigned int	num;
	int				i;
	char			*str;

	dat = ft_precwi(list, dat);
	num = va_arg(*list, unsigned int);
	str = ft_itoa_base(num, "0123456789ABCDEF");
	ft_rev(str, ft_strlen(str));
	if (str[0] == '0' && dat.prec == 0)
	{
		str = "";
		dat.zeroflag = 0;
	}
	i = ft_putstr3(str, ft_strlen(str), dat);
	return (i);
}

int					ft_code_pour(va_list *list, t_convdata dat)
{
	int i;

	(void)list;
	i = 0;
	if (!dat.minusflag)
	{
		while (i < dat.width - 1)
		{
			if (dat.zeroflag)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i++;
		}
	}
	write(1, "%", 1);
	if (dat.minusflag)
	{
		while (i < dat.width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + 1);
}

struct	s_convdata	ft_balec(const char c, t_convdata dat)
{
	if (c == '-')
		dat.minusflag = 1;
	else if (c == '0')
		dat.zeroflag = 1;
	else if (c == '*')
		dat.width = -2;
	return (dat);
}

struct s_convdata	ft_data_ini(void)
{
	t_convdata data;

	data.minusflag = 0;
	data.zeroflag = 0;
	data.width = -1;
	data.prec = -1;
	return (data);
}
