/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:16:26 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:16:31 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writezero(int prec, int i)
{
	while (prec > 1)
	{
		write(1, "0", 1);
		prec--;
		i++;
	}
	write(1, "0", 1);
	i++;
	return (i);
}

int	ft_zerofunct(t_convdata dat)
{
	int i;
	int widthval;

	i = 0;
	if (dat.prec > 1)
		widthval = dat.width - dat.prec;
	else
	{
		if (dat.prec == 0)
		{
			widthval = dat.width;
			dat.zeroflag = 0;
		}
		else
			widthval = dat.width - 1;
	}
	if (!dat.minusflag)
		i = ft_widthmaker(i, widthval, dat);
	if (dat.prec == 0)
		;
	else
		i = ft_writezero(dat.prec, i);
	if (dat.minusflag)
		i = ft_widthmaker(i, dat.width, dat);
	return (i);
}
