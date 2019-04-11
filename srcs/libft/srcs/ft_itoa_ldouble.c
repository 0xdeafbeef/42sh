/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:15:32 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/21 13:51:51 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned long	get_pow(int prec)
{
	long	i;

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

static	char			*get_zero(t_ldouble d, int prec)
{
	int			i;
	char		*tmp;

	if (!(tmp = ft_strdup("0")))
		return (NULL);
	if ((!d.data[0] && (d.data[1] == 32768)) &&
			!(tmp = ft_strjoin_free("-", tmp, 2)))
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

static char				*prepare_string(int prec, long double tmp, char **str,
										long double d)
{
	int			i;

	i = 1;
	while (tmp < 0.1 && tmp)
	{
		++i;
		tmp *= 10;
	}
	if (prec && !(str[0] = ft_strjoin_free(str[0], ".", 1)))
		return (NULL);
	i = ((prec > 0 && (i >= prec || !tmp)) ? prec : i);
	i = ((prec == -1 && (i > 6 || !tmp)) ? 6 : i);
	while (prec && --i)
		str[0] = ft_strjoin_free(str[0], "0", 1);
	tmp = ((d < 0) ? -d + (long)d : d - (long)d) * get_pow(prec);
	if (prec && !(str[1] = ft_itoa_base(ft_itoa_round((double)tmp), 10, 0)))
		return (NULL);
	if (prec && !(str[0] = ft_strjoin_free(str[0], str[1], 3)))
		return (NULL);
	i = prec - 19;
	while (i-- > 0)
		if (!(str[0] = ft_strjoin_free(str[0], "0", 1)))
			return (NULL);
	return (str[0]);
}

static char				*get_nbr(long double d, int prec)
{
	char		*str[2];
	int			i;
	long double	tmp;

	if (!(!(long)d && d < 0) && prec && !(str[0] =
				ft_itoa_base((long)d, 10, 0)))
		return (NULL);
	if (!(!(long)d && d < 0) && !prec && !(str[0] =
				ft_itoa_base(ft_itoa_round((double)d), 10, 0)))
		return (NULL);
	if (!(long)d && d < 0 && !(str[0] = ft_strdup("-0")))
		return (NULL);
	i = 1;
	tmp = ((d < 0) ? -d + (long)d : d - (long)d);
	return (prepare_string(prec, tmp, str, d));
}

char					*ft_itoa_ldouble(long double value, int prec)
{
	t_ldouble	d;

	d.d = value;
	if ((!d.data[0] && !d.data[1]) || (!d.data[0] && (d.data[1] == 32768)))
		return (get_zero(d, prec));
	if ((d.data[0] == 13835058055282163712U) && (d.data[1] == 32767))
		return (ft_strdup("nan"));
	if ((d.data[0] == 9223372036854775808U) && (d.data[1] == 32767))
		return (ft_strdup("inf"));
	if ((d.data[0] == 9223372036854775808U) && (d.data[1] == 65535))
		return (ft_strdup("-inf"));
	return (get_nbr(value, prec));
}
