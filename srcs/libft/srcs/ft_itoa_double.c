/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:56:42 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/21 14:52:53 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned long	get_pow(int prec)
{
	long		i;

	i = 10;
	if (prec < 0)
		return (1000000);
	else if (!prec)
		return (0);
	else if (prec >= 19)
		return (10000000000000000000U);
	else
	{
		while (--prec)
			i *= 10;
	}
	return (i);
}

static	char			*get_zero(t_double d, int prec)
{
	int			i;
	char		*tmp;

	if (!(tmp = ft_strdup("0")))
		return (NULL);
	if (((d.data >> 63) != 0) && !(tmp = ft_strjoin_free("-", tmp, 2)))
		return (NULL);
	if (!prec)
		return (tmp);
	if (!(tmp = ft_strjoin_free(tmp, ".", 1)))
		return (NULL);
	if ((prec == -1) && !(tmp = ft_strjoin_free(tmp, "000000", 1)))
		return (NULL);
	i = -1;
	if (prec > 0)
		while (++i < prec)
			if (!(tmp = ft_strjoin_free(tmp, "0", 1)))
				return (NULL);
	return (tmp);
}

static	char			*prepare_string(int prec, double tmp, char **str,
										t_double d)
{
	int			i;

	i = 1;
	while (tmp < 0.1 && tmp)
	{
		++i;
		tmp *= 10;
	}
	i = ((prec > 0 && (i >= prec || !tmp)) ? prec : i);
	i = ((prec == -1 && (i > 6 || !tmp)) ? 6 : i);
	while (prec && --i)
		str[0] = ft_strjoin_free(str[0], "0", 1);
	tmp = ((d.d > 0) ? d.d - (long)d.d : -d.d + (long)d.d) * get_pow(prec);
	if (prec && !(str[1] = ft_itoa_base(ft_itoa_round(tmp), 10, 0)))
		return (NULL);
	if (prec && !(str[0] = ft_strjoin_free(str[0], str[1], 3)))
		return (NULL);
	i = prec - 19;
	while (i-- > 0)
		if (!(str[0] = ft_strjoin_free(str[0], "0", 1)))
			return (NULL);
	return (str[0]);
}

static	char			*get_nbr(t_double d, int prec)
{
	char		*str[2];
	int			i;
	double		tmp;

	if (!(!(long)d.d && d.d < 0) && prec && !(str[0] =
				ft_itoa_base((long)d.d, 10, 0)))
		return (NULL);
	if (!(!(long)d.d && d.d < 0) && !prec && !(str[0] =
				ft_itoa_base(ft_itoa_round((double)d.d), 10, 0)))
		return (NULL);
	if (!(long)d.d && d.d < 0 && !(str[0] = ft_strdup("-0")))
		return (NULL);
	i = 1;
	tmp = ((d.d > 0) ? d.d - (long)d.d : -d.d + (long)d.d);
	if (prec && !(str[0] = ft_strjoin_free(str[0], ".", 1)))
		return (NULL);
	return (prepare_string(prec, tmp, str, d));
}

char					*ft_itoa_double(double value, int prec)
{
	t_double	d;

	d.d = value;
	if (!((d.data >> 52) & 2047))
		return (get_zero(d, prec));
	if (((d.data >> 52) & 2047) == 2047)
	{
		if ((d.data & 4503599627370495) == 0)
		{
			if (d.data >> 63)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
		}
		else
			return (ft_strdup("nan"));
	}
	return (get_nbr(d, prec));
}
