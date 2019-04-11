/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:07:16 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/31 18:00:24 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisint(char *str)
{
	int		i;
	long	a;

	i = -1;
	a = ft_atol(str);
	if (str[++i] == '-' && !str[1])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (a > 2147483647 || a < -2147483648 || ft_strlen(str) > 11)
		return (0);
	return (1);
}
