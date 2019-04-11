/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:15:31 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/18 12:46:04 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len(unsigned long n)
{
	int		len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa_u(unsigned long n)
{
	char	*str;
	int		len;

	len = get_len(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)))
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
		return (str);
	}
	return (NULL);
}
