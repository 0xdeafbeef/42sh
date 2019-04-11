/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:39:26 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/19 16:47:53 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_specs(va_list ap, t_spec *spec)
{
	if (spec->spec == 'i' || spec->spec == 'd')
		c_di(spec, va_arg(ap, long long));
	else if (spec->spec == 'u')
		c_u(spec, va_arg(ap, unsigned long long));
	else if (spec->spec == 'c')
		c_c(spec, va_arg(ap, int));
	else if (spec->spec == 's')
		c_s(spec, va_arg(ap, char*));
	else if (spec->spec == 'p')
		c_p(spec, va_arg(ap, void*));
	else if (spec->spec == 'o')
		c_o(spec, va_arg(ap, unsigned long long));
	else if (spec->spec == 'X')
		c_x(spec, va_arg(ap, unsigned long long), 1);
	else if (spec->spec == 'x')
		c_x(spec, va_arg(ap, unsigned long long), 0);
	else if (spec->spec == 'b')
		c_b(spec, va_arg(ap, unsigned long));
	else if (spec->spec == 'f' && !spec->len[3])
		c_dd(spec, va_arg(ap, double));
	else if (spec->spec == 'f' && spec->len[3])
		c_ld(spec, va_arg(ap, long double));
	else if (spec->spec == '%')
		if (!(spec->cont = ft_strdup("%")))
			return ;
}

void		set_cont(va_list ap, t_spec *spec, int count)
{
	while (count--)
	{
		set_specs(ap, spec);
		prec(spec);
		change_width(spec);
		++spec;
	}
}
