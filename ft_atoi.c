/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:18:03 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:29:38 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_isspace(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\f' || str[i] == 32)
		i++;
	return (i);
}

int					r_atoi(char *strf)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (strf[i] > 47 && strf[i] < 58)
	{
		result = result * 10 + (strf[i] - 48);
		i++;
	}
	return (result);
}

int					ft_atoi(char *str)
{
	int result;
	int sign;
	int index;

	result = 0;
	sign = 1;
	index = ft_isspace(str);
	while (str[index])
	{
		if (str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-')
				sign = sign * -1;
			index++;
		}
		else if (str[index] > 47 && str[index] < 58)
		{
			result = r_atoi(&str[index]);
			return (result * sign);
		}
		else
			return (0);
	}
	return (0);
}

struct s_convdata	ft_precwi(va_list *list, t_convdata dat)
{
	t_convdata dat2;

	dat2 = dat;
	if (dat.width == -2)
	{
		dat2.width = va_arg(*list, int);
		if (dat2.width < 0)
		{
			dat2.width *= -1;
			dat2.minusflag = 1;
		}
	}
	if (dat.prec == -2)
	{
		dat2.prec = va_arg(*list, int);
		if (dat2.prec < 0)
			dat2.prec = -1;
	}
	return (dat2);
}

long				ft_writenbr(long nb, long divider)
{
	long temp;
	char c;

	temp = nb / divider;
	c = (temp % 10) + 48;
	write(1, &c, 1);
	return (divider /= 10);
}
