/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:16:05 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:30:25 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_code_di(va_list *list, t_convdata dat)
{
	int num;
	int i;

	dat = ft_precwi(list, dat);
	num = va_arg(*list, int);
	i = ft_putnbr(num, dat);
	return (i);
}

int	ft_code_u(va_list *list, t_convdata dat)
{
	unsigned int	num;
	int				i;

	dat = ft_precwi(list, dat);
	num = va_arg(*list, int);
	i = ft_putnbr(num, dat);
	return (i);
}

int	ft_code_p(va_list *list, t_convdata dat)
{
	void	*adress;
	char	*str;
	int		i;

	dat = ft_precwi(list, dat);
	adress = va_arg(*list, void*);
	str = ft_itoa_base((unsigned long)adress, "0123456789abcdef");
	if ((unsigned long)adress == 0 && dat.prec == 0)
		str = "0x";
	else
	{
		i = ft_strlen(str);
		str[i++] = 'x';
		str[i++] = '0';
		ft_rev(str, i);
		str[i] = 0;
	}
	i = ft_putstr(str, dat);
	return (i);
}

int	ft_code_s(va_list *list, t_convdata dat)
{
	char	*string;
	int		i;

	dat = ft_precwi(list, dat);
	string = va_arg(*list, char*);
	if (string == NULL)
		string = "(null)";
	if (dat.prec == -1)
		i = ft_putstr(string, dat);
	else
		i = ft_putstr2(string, dat);
	return (i);
}

int	ft_code_c(va_list *list, t_convdata dat)
{
	char	cara;
	int		i;

	i = 0;
	dat = ft_precwi(list, dat);
	cara = va_arg(*list, int);
	if (!dat.minusflag)
	{
		while (i < dat.width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	write(1, &cara, 1);
	if (dat.minusflag)
	{
		while (i < dat.width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (1 + i);
}
