/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:39:38 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/07 13:55:02 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisint(char *str)
{
	long check;

	check = ft_atol(str);
	if (check > 2147483647 || check < -2147483648 || ft_strlen(str) > 11)
		return (0);
	if (str[0] == '-' && str[1])
		++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		++str;
	}
	return (1);
}
