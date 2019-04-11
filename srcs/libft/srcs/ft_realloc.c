/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:44:47 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/06 19:47:34 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void *new;

	if (!ptr)
		return (NULL);
	if (!(new = malloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, prev_size < new_size ? prev_size : new_size);
	free(ptr);
	return (new);
}
