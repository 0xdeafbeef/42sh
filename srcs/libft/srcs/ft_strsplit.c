/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:36:05 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/07 16:32:07 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	get_num(char *s, char c)
{
	int		i;
	int		num;

	i = -1;
	num = 0;
	while (s[++i])
		if (s[i] == c && i - 1 >= 0 && s[i - 1] != c)
			num++;
	num += ((i > 0 && s[i - 1] != c) ? 1 : 0);
	num += ((!num && s[0] && s[0] != c) ? 1 : 0);
	return (num);
}

static	int	get_len(char *str, char c)
{
	int		len;

	len = -1;
	while (str[++len] != c && str[len])
		;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		num;

	if (!s || !c)
		return (NULL);
	while (*s && *s == c)
		++s;
	num = get_num((char*)s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * num + 1 * sizeof(char*))))
		return (NULL);
	i = -1;
	while (++i < num)
	{
		if (!(arr[i] = (char*)malloc(sizeof(char) * get_len((char*)s, c) + 1)))
			return (NULL);
		ft_strncpy(arr[i], (char*)s, get_len((char*)s, c));
		arr[i][get_len((char*)s, c)] = '\0';
		s += ((i == num - 1) ? 0 : get_len((char*)s, c));
		while (*s == c)
			++s;
	}
	arr[i] = NULL;
	return (arr);
}
