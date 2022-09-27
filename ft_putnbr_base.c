/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:17:31 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:34:20 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

unsigned long	ft_strlen(char *str)
{
	unsigned long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putchar2(char c)
{
	write(1, &c, 1);
}

int				ft_checkbase(char *base, unsigned long baselen)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (baselen <= 1)
		return (1);
	else
	{
		while (base[i])
		{
			while (base[i] != base[j] && base[j]
					&& base[i] != '+' && base[i] != '-')
				j++;
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (1);
			i++;
			j = i + 1;
		}
		return (0);
	}
}

int				ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	nbr2;
	unsigned long	d;
	unsigned long	baselen;
	static int		i = 0;

	nbr2 = nbr;
	baselen = ft_strlen(base);
	if (ft_checkbase(base, baselen))
		return (0);
	d = nbr2;
	if (d >= baselen)
		i = ft_putnbr_base(d / baselen, base);
	ft_putchar2(base[d % baselen]);
	return (i + 1);
}

int				ft_isnegative(long *nb)
{
	if (*nb < 0)
	{
		*nb *= -1;
		return (1);
	}
	else
		return (0);
}
