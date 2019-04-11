/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:36:13 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/19 16:42:47 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			check_spec(const char **str)
{
	if (*(++(*str)) == '%')
		return (1);
	while (**str == '#' || **str == '-' || **str == '0' || **str == '+' ||
		**str == ' ')
		(*str)++;
	while (**str >= '0' && **str <= '9')
		(*str)++;
	if (**str == '.')
		while (*(++(*str)) >= '0' && **str <= '9')
			;
	if (**str == 'h' || **str == 'l' || **str == 'L')
	{
		(*str)++;
		if ((*(*str - 1) == 'h' && **str == 'h') || (*(*str - 1) == 'l' &&
			**str == 'l'))
			(*str)++;
	}
	while (**str == '#' || **str == '-' || **str == '0' || **str == '+' ||
		**str == ' ')
		(*str)++;
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'o' || **str == 'u' || **str == 'x' ||
		**str == 'X' || **str == 'b' || **str == '%' || **str == 'f')
		return (1);
	return (0);
}

int			count_spec(const char *format, t_spec *spec)
{
	int		count;

	count = 0;
	while (*format)
	{
		if (*format && *format == '%' && *(format + 1) && check_spec(&format))
		{
			if (spec)
			{
				(*spec).pos = (char*)format;
				(*spec).spec = *format;
				spec++;
			}
			count++;
		}
		format++;
	}
	return (count);
}

void		set_spec(t_spec *spec, int count)
{
	int		i;
	int		j;
	int		len;
	char	*cur;

	i = -1;
	while (++i < count)
	{
		len = 1;
		cur = spec[i].pos;
		while (*(--cur) != '%')
			len++;
		spec[i].pos = cur;
		spec[i].del = len + 1;
		spec[i].prec = -1;
		j = -1;
		while (++j < 4)
			spec[i].len[j] = 0;
		j = -1;
		while (++j < 5 || (spec[i].neg = 0))
			spec[i].flag[j] = 0;
		if ((spec[i].width = 0) || len == 1)
			continue ;
		set_spec_arrs(spec, i, cur);
	}
}

static void	set_spec_flags(t_spec *spec, char *cur, int i)
{
	if (*cur == '#')
		spec[i].flag[0] = 1;
	else if (*cur == '0')
		spec[i].flag[1] = 1;
	else if (*cur == '-')
		spec[i].flag[2] = 1;
	else if (*cur == ' ')
		spec[i].flag[3] = 1;
	else if (*cur == '+')
		spec[i].flag[4] = 1;
	else if (*cur == 'h' && *(cur + 1) != 'h' && *(cur - 1) != 'h')
		spec[i].len[0] = 1;
	else if (*cur == 'h' && *(cur + 1) == 'h')
		spec[i].len[1] = 1;
	else if (*cur == 'l' && *(cur + 1) != 'l' && *(cur - 1) != 'l')
		spec[i].len[2] = 1;
	else if ((*cur == 'l' && *(cur + 1) == 'l') || *cur == 'L')
		spec[i].len[3] = 1;
}

void		set_spec_arrs(t_spec *spec, int i, char *cur)
{
	while (*(++cur) && *cur != spec[i].spec)
	{
		set_spec_flags(spec, cur, i);
		if ((*cur >= '0' && *cur <= '9') || *cur == '.')
		{
			if (*cur == '.')
				spec[i].prec = ft_atoi(cur + 1);
			else
				spec[i].width = ft_atoi(cur);
			while (*(cur + 1) >= '0' && *(cur + 1) <= '9')
				cur++;
		}
	}
}
