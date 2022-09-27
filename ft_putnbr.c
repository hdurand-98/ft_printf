/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:31:11 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:33:46 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthmaker(int i, int widthval, t_convdata dat)
{
	while (i < widthval)
	{
		if (dat.zeroflag && dat.prec == -1 && !dat.minusflag)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (i);
}

long	ft_nbidentifier(long nb2, int prec, int *precvalue)
{
	long	divider;
	int		i;

	i = 0;
	*precvalue = 0;
	divider = 1;
	while (nb2 / divider > 0)
	{
		divider *= 10;
		i++;
	}
	while (*precvalue < prec - i)
		++*precvalue;
	return (divider / 10);
}

int		ft_width(int div, int width)
{
	int i;
	int widthval;

	widthval = 0;
	i = 0;
	while (div >= 1)
	{
		div /= 10;
		i++;
	}
	while (widthval + i < width)
		widthval++;
	return (widthval);
}

int		ft_writer(int prec, int wid, int nega, t_convdata dat)
{
	int i;
	int minuspos;

	i = 0;
	minuspos = 0;
	if (nega)
	{
		if (dat.prec == -1 && dat.zeroflag)
		{
			write(1, "-", 1);
			minuspos = 1;
		}
		i++;
	}
	if (!dat.minusflag)
		i = ft_widthmaker(i, wid - prec, dat);
	if (nega && !minuspos)
		write(1, "-", 1);
	while (prec > 0)
	{
		write(1, "0", 1);
		i++;
		prec--;
	}
	return (i);
}

int		ft_putnbr(long nb, t_convdata dat)
{
	long	divider2;
	int		prec;
	long	number;
	int		width;
	int		i;

	i = 0;
	number = nb;
	ft_isnegative(&nb);
	if (nb == 0)
		return (ft_zerofunct(dat));
	divider2 = ft_nbidentifier(nb, dat.prec, &prec);
	width = ft_width(divider2, dat.width);
	i += ft_writer(prec, width, ft_isnegative(&number), dat);
	while (divider2 >= 1)
	{
		divider2 = ft_writenbr(nb, divider2);
		i++;
	}
	if (dat.minusflag == 1)
		i = ft_widthmaker(i, dat.width, dat);
	return (i);
}
