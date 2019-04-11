/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:35:07 by hkuphal           #+#    #+#             */
/*   Updated: 2019/01/26 10:18:04 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen_chr(const char *s, char *c)
{
	const char *tmp;

	tmp = s;
	while (*tmp && tmp != c)
		++tmp;
	return (tmp - s);
}
