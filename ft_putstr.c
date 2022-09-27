/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:01:36 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:50:47 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_widthval(int len, t_convdata dat)
{
	int temp;

	if (dat.prec == -1)
		dat.prec = 0;
	temp = dat.prec - len;
	if (temp > 0)
		return (dat.width - dat.prec);
	else
		return (dat.width - len);
}

int	ft_widthval2(int len, t_convdata dat)
{
	int temp;

	temp = dat.prec - len;
	if (temp < 0)
		return (dat.width - dat.prec);
	else
		return (dat.width - len);
}

int	ft_putstr(char *s, t_convdata dat)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (s == NULL)
		return (0);
	if (!dat.minusflag)
		i = ft_widthmaker(i, dat.width - ft_strlen(s), dat);
	while (s[y] != 0)
	{
		write(1, &s[y], 1);
		y++;
	}
	if (dat.minusflag)
		y = ft_widthmaker(y, dat.width, dat);
	return (i + y);
}

int	ft_putstr2(char *s, t_convdata dat)
{
	int i;
	int y;
	int widthval;

	i = 0;
	y = 0;
	widthval = ft_widthval2(ft_strlen(s), dat);
	if (!dat.minusflag)
	{
		while (i < widthval)
		{
			write(1, " ", 1);
			i++;
		}
	}
	while (s[y] != 0 && y <= dat.prec - 1)
	{
		write(1, &s[y], 1);
		y++;
	}
	if (dat.minusflag)
		y = ft_widthmaker(y, dat.width, dat);
	return (i + y);
}

int	ft_putstr3(char *s, int len, t_convdata dat)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (!dat.minusflag)
		i = ft_widthmaker(i, ft_widthval(len, dat), dat);
	while (dat.prec > len)
	{
		write(1, "0", 1);
		i++;
		dat.prec--;
	}
	while (s[y] != 0)
	{
		write(1, &s[y], 1);
		y++;
	}
	if (dat.minusflag)
		i = ft_widthmaker(i, dat.width - y, dat);
	return (i + y);
}
