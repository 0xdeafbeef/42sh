/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:23:49 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/19 16:14:07 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa_pointer(void *p)
{
	char	*buff2;
	char	*str;
	long	shift;
	long	tmp;
	int		flag;

	shift = 15;
	flag = 0;
	if (!(str = ft_strnew(1)))
		return (NULL);
	while (shift >= 0)
	{
		tmp = ((long)p >> (shift * 4)) & 15;
		if (!flag && shift != 1 && tmp == 0 && shift--)
			continue ;
		else
			flag = 1;
		if (!(buff2 = ft_itoa_base(tmp, 16, 0)))
			return (NULL);
		if (!(str = ft_strjoin_free(str, buff2, 3)))
			return (NULL);
		--shift;
	}
	return (str);
}
