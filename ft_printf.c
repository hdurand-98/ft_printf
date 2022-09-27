/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 20:05:23 by hdurand           #+#    #+#             */
/*   Updated: 2020/08/19 22:12:08 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*g_tabfunc[9]) (va_list*, t_convdata) = {
	ft_code_di,
	ft_code_di,
	ft_code_s,
	ft_code_c,
	ft_code_x,
	ft_code_ux,
	ft_code_u,
	ft_code_p,
	ft_code_pour};

int	ft_indexfinder(char *tabelem, char element)
{
	int index;

	index = 0;
	while (tabelem[index] != 0)
	{
		if (tabelem[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_check(char c, char *str)
{
	int i;

	i = 0;
	while (c != str[i] && str[i])
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}

int	ft_searchprecwi(const char *str, int *index)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	if (!(ptr = malloc(sizeof(char*) * (j - i) + 1)))
		return (-3);
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ptr[j++] = str[i++];
		*index += 1;
	}
	*index -= 1;
	ptr[j] = 0;
	j = ft_atoi(ptr);
	free(ptr);
	return (j);
}

int	ft_corevalues(const char *src, int (*tabfunc[9]) (va_list *, t_convdata),
		char *elements, va_list *my_list)
{
	int			i;
	int			returnvalue;
	int			tabindex;
	t_convdata	dat;

	i = -1;
	returnvalue = 0;
	while (src[++i])
	{
		if (src[i] == '%')
		{
			dat = ft_convdata(&src[++i], &i);
			if (dat.width == -3 || dat.prec == -3)
				return (-1);
			if (ft_indexfinder(elements, src[i]) != -1)
			{
				tabindex = ft_indexfinder(elements, src[i]);
				if (tabindex != -1)
					returnvalue += tabfunc[tabindex](my_list, dat);
			}
		}
		else
			returnvalue += ft_putchar(src[i]);
	}
	return (returnvalue);
}

int	ft_printf(const char *src, ...)
{
	char	*elements;
	va_list my_list;
	int		i;

	elements = "discxXup%";
	va_start(my_list, src);
	i = ft_corevalues(src, g_tabfunc, elements, &my_list);
	va_end(my_list);
	return (i);
}
