/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:32:39 by hkuphal           #+#    #+#             */
/*   Updated: 2018/11/23 13:15:43 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_chr(char const *s, char *c)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen_chr(s, c);
		write(1, s, len);
	}
}
