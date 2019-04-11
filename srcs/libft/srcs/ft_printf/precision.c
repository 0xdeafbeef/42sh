/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:42:21 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/21 14:00:54 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	change_prec(int *len, t_spec *spec, int *flag)
{
	++(*len);
	if (NEG)
	{
		*flag = 1;
		CONT[0] = '0';
		CONT = ft_strjoin_free("0", CONT, 2);
	}
	while (--(*len))
		spec->cont = ft_strjoin_free("0", CONT, 2);
	if (*flag)
		CONT[0] = '-';
}

void			prec(t_spec *spec)
{
	int		flag;
	int		len;
	char	*tmp;

	flag = 0;
	len = spec->prec - ft_strlen(CONT);
	if (!ft_strcmp(CONT, "0") && !PREC && NUM)
	{
		free(CONT);
		CONT = ((O && spec->flag[0]) ? ft_strdup("0") : ft_strnew(1));
	}
	if (len >= 0 && NUM)
		change_prec(&len, spec, &flag);
	else if (len < 0)
	{
		if (STR)
		{
			tmp = ft_strnew(ft_strlen(CONT));
			tmp = ft_strncat(tmp, CONT, PREC);
			free(CONT);
			CONT = tmp;
		}
	}
}

static	int		get_flag(t_spec *spec, int *len)
{
	int		flag;

	flag = 0;
	if (D && NEG && spec->flag[1])
	{
		flag = 1;
		spec->cont[0] = '0';
	}
	else if ((D || F) && !NEG && spec->flag[3] && !spec->flag[4])
	{
		--(*len);
		flag = 2;
	}
	else if ((D || F) && !NEG && spec->flag[4])
		flag = 3;
	return (flag);
}

static	void	change_width_new(int *flag, t_spec *spec, int *len)
{
	if (*flag == 1)
		spec->cont[0] = '-';
	else if (*flag == 2)
		spec->cont = ft_strjoin_free(" ", spec->cont, 2);
	else if (*flag == 3 && !spec->neg)
	{
		--(*len);
		spec->cont = ft_strjoin_free("+", spec->cont, 2);
	}
	if (*len > 0)
	{
		++(*len);
		while (spec->flag[2] && --(*len))
			spec->cont = ft_strjoin_free(spec->cont, " ", 1);
		while (!spec->flag[2] && --(*len))
			spec->cont = ft_strjoin_free(" ", spec->cont, 2);
	}
}

void			change_width(t_spec *spec)
{
	int		len;
	int		flag;

	len = spec->width - ft_strlen(CONT) - ((C && NEG) ? 1 : 0);
	flag = get_flag(spec, &len);
	if (X && spec->flag[0] && ft_atoi(CONT))
		len -= 2;
	if ((len > 0 && spec->flag[1] && !spec->flag[2]) && (PREC == -1 || !FNUM))
	{
		++len;
		if (!NEG && spec->flag[4])
			--len;
		while (!spec->flag[2] && --len)
			CONT = ft_strjoin_free("0", CONT, 2);
	}
	if (SPEC == 'x' && spec->flag[0] && ft_atoi(CONT) && ft_strlen(CONT))
		CONT = ft_strjoin_free("0x", CONT, 2);
	if (SPEC == 'X' && spec->flag[0] && ft_atoi(CONT) && ft_strlen(CONT))
		CONT = ft_strjoin_free("0X", CONT, 2);
	change_width_new(&flag, spec, &len);
}
