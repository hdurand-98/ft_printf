/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:18:24 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 21:48:44 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int					numlen(unsigned long num)
{
	int				i;
	unsigned long	nb;

	nb = num;
	i = 0;
	while (nb / 16 >= 1)
	{
		i++;
		nb = nb / 16;
	}
	return (i + 1);
}

void				ft_rev(char *tab, int size)
{
	int temp;
	int turn;

	turn = size / 2;
	while (turn > 0)
	{
		temp = tab[size - turn];
		tab[size - turn] = tab[turn - 1];
		tab[turn - 1] = temp;
		turn--;
	}
}

char				*ft_itoa_base(unsigned long num, char *base)
{
	unsigned long	nb;
	char			*str;
	int				len;
	int				i;

	i = 0;
	nb = num;
	len = numlen(num);
	if (!(str = malloc((sizeof(char *) * len) + 3)))
		return (NULL);
	while (i < len)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[i] = 0;
	return (str);
}

int					ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

struct s_convdata	ft_convdata(const char *str, int *y)
{
	t_convdata	data;
	int			i;

	data = ft_data_ini();
	i = 0;
	while (ft_check(str[i], "diuscxXp%"))
	{
		data = ft_balec(str[i], data);
		if (str[i] >= '0' && str[i] <= '9' && data.width != -2)
			data.width = ft_searchprecwi(&str[i], &i);
		else if (str[i] == '.')
		{
			if (str[++i] == '*')
				data.prec = -2;
			else
				data.prec = ft_searchprecwi(&str[i], &i);
		}
		i++;
	}
	if (data.minusflag == 1 && data.zeroflag == 1)
		data.zeroflag = 0;
	*y += i;
	return (data);
}
