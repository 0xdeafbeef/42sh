/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:31:47 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/07 18:51:27 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_getchar(void)
{
	static char	buf[BUFSZ];
	static char	*bufp = buf;
	static int	n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
