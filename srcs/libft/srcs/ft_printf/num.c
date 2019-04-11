/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:29:55 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/19 16:59:20 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		c_di(t_spec *spec, long nb)
{
	if (spec->len[0] && !(spec->cont = ft_itoa_base((short)nb, 10, 3)))
		return (-1);
	if (spec->len[1] && !(spec->cont = ft_itoa_base((signed char)nb, 10, 2)))
		return (-1);
	if ((!spec->len[3] && !spec->len[2] && !spec->len[0] && !spec->len[1])
		&& !(spec->cont = ft_itoa_base((int)nb, 10, 0)))
		return (-1);
	if ((spec->len[2] || spec->len[3]) && !(spec->cont =
		ft_itoa_base(nb, 10, 0)))
		return (-1);
	spec->neg = ((spec->cont[0] == '-') ? 1 : 0);
	return (1);
}

int		c_o(t_spec *spec, unsigned long i)
{
	if ((spec->len[2] || spec->len[3]) && !(spec->cont = ft_itoa_bin(i, 8, 0)))
		return (-1);
	if (spec->len[1] && !(spec->cont = ft_itoa_bin((unsigned char)i, 8, 0)))
		return (-1);
	if (spec->len[0] && !(spec->cont = ft_itoa_bin((unsigned short)i, 8, 0)))
		return (-1);
	if (NOLEN && !(spec->cont = ft_itoa_bin((unsigned int)i, 8, 0)))
		return (-1);
	if (O && spec->flag[0] && ft_strcmp(CONT, "0") && ft_strlen(CONT))
		CONT = ft_strjoin_free("0", CONT, 2);
	return (1);
}

int		c_u(t_spec *spec, unsigned long i)
{
	if ((spec->len[2] || spec->len[3]) && !(spec->cont = ft_itoa_u(i)))
		return (-1);
	if (spec->len[1] && !(spec->cont = ft_itoa_u((unsigned char)i)))
		return (-1);
	if (spec->len[0] && !(spec->cont = ft_itoa_u((unsigned short)i)))
		return (-1);
	if (NOLEN && !(spec->cont = ft_itoa_u((unsigned int)i)))
		return (-1);
	return (1);
}

int		c_x(t_spec *spec, unsigned long x, int i)
{
	if ((spec->len[2] || spec->len[3]) && !(spec->cont = ft_itoa_bin(x, 16, i)))
		return (-1);
	if (spec->len[1] && !(spec->cont = ft_itoa_bin((unsigned char)x, 16, i)))
		return (-1);
	if (spec->len[0] && !(spec->cont = ft_itoa_bin((unsigned short)x, 16, i)))
		return (-1);
	if (NOLEN && !(spec->cont = ft_itoa_bin((unsigned int)x, 16, i)))
		return (-1);
	return (1);
}
