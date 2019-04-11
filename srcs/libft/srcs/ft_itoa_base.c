/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:24:01 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/17 17:12:40 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*check_value(long value)
{
	if (value == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-9223372036854775808"));
}

static void	get_len(int *len, long *nbr, int base, int i)
{
	long	value;

	if (*nbr < 0 || (i == 2 && (signed char)*nbr < 0))
	{
		if (base == 10)
			*len += 1;
		*nbr *= -1;
	}
	value = *nbr;
	while (value)
	{
		value /= base;
		*len += 1;
	}
}

char		*ft_itoa_base(long value, int base, int i)
{
	int		len;
	long	nbr;
	char	*str;
	char	*base_string;

	base_string = ((i) ? "0123456789ABCDEF" : "0123456789abcdef");
	if (value == 0 || (unsigned long)value == -9223372036854775808U)
		return (check_value(value));
	len = 0;
	nbr = value;
	get_len(&len, &nbr, base, i);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if ((value < 0 || (i == 2 && (signed char)value < 0)) && base == 10)
		str[0] = '-';
	return (str);
}
