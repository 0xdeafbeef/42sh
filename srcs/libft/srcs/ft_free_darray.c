/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:25:21 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/11 14:41:04 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_darray(char **args)
{
	int		i;
	int		count;

	i = -1;
	count = ft_arr_word_count(args);
	while (++i < count)
		free(args[i]);
	free(args);
}
