/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:13:48 by dmorgil           #+#    #+#             */
/*   Updated: 2019/03/06 15:39:25 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("arr[%d] = %d\n", i, array[i]);
		i++;
	}
}
