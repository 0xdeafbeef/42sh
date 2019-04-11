/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:07:35 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:52:47 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char const *s1, char const *s2, int k)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
					+ 1)))
	{
		ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		if (k == 1)
			free((char *)s1);
		else if (k == 2)
			free((char *)s2);
		else if (k == 3)
		{
			free((char *)s1);
			free((char *)s2);
		}
		return (str);
	}
	return (NULL);
}
