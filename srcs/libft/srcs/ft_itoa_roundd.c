/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_roundd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:05:28 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/21 14:55:02 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_itoa_round(double tmp)
{
	int		sign;

	sign = 1;
	if (tmp < 0)
	{
		tmp = -tmp;
		sign = -1;
	}
	if ((long)(tmp * 10) - (long)tmp * 10 >= 5)
		return (((long)(tmp) + 1) * sign);
	return ((long)tmp * sign);
}
