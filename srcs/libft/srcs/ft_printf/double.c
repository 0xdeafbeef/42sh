/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:58:21 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/21 14:43:45 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_dd(t_spec *spec, double d)
{
	if (!(spec->cont = ft_itoa_double(d, PREC)))
		return (-1);
	spec->neg = ((spec->cont[0] == '-') ? 1 : 0);
	if (spec->flag[0] && !PREC)
		CONT = ft_strjoin_free(CONT, ".", 1);
	return (1);
}

int		c_ld(t_spec *spec, long double d)
{
	if (!(spec->cont = ft_itoa_ldouble(d, PREC)))
		return (-1);
	spec->neg = ((spec->cont[0] == '-') ? 1 : 0);
	if (spec->flag[0] && !PREC)
		CONT = ft_strjoin_free(CONT, ".", 1);
	return (1);
}

int		c_p(t_spec *spec, void *p)
{
	if (!p)
	{
		if (!(CONT = ft_strdup("0x")))
			return (-1);
		if (PREC == -1 && !(CONT = ft_strjoin_free(CONT, "0", 1)))
			return (-1);
		if (PREC > (int)ft_strlen(CONT) - 2)
			while (PREC--)
				if (!(CONT = ft_strjoin_free(CONT, "0", 1)))
					return (-1);
	}
	if (p && !(CONT = ft_itoa_pointer(p)))
		return (-1);
	if (p && PREC > (int)ft_strlen(CONT) - 2)
	{
		PREC -= ft_strlen(CONT);
		while (PREC-- > 0)
			if (!(CONT = ft_strjoin_free("0", CONT, 2)))
				return (-1);
	}
	if (p && !(CONT = ft_strjoin_free("0x", CONT, 2)))
		return (-1);
	return (1);
}

int		c_b(t_spec *spec, unsigned long b)
{
	if (!(spec->cont = ft_itoa_bin(b, 2, 0)))
		return (-1);
	return (1);
}
