/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:59:02 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/26 12:19:13 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define SPEC spec->spec
# define CONT spec->cont
# define PREC spec->prec
# define NEG spec->neg
# define D (SPEC == 'd' || SPEC == 'i')
# define O (SPEC == 'o')
# define U (SPEC == 'u')
# define X (SPEC == 'x' || SPEC == 'X')
# define NUM (D || O || X || U)
# define F (SPEC == 'f')
# define FNUM (F || NUM)
# define STR (SPEC == 's')
# define C (SPEC == 'c')
# define NOLEN !(spec->len[0] || spec->len[1] || spec->len[2] || spec->len[3])

typedef struct	s_spec
{
	char	spec;
	int		flag[5];
	int		prec;
	int		len[4];
	int		width;
	char	*pos;
	char	*cont;
	int		del;
	int		neg;
}				t_spec;

void			prec(t_spec *spec);
void			change_width(t_spec *spec);
int				check_spec(const char **str);
int				count_spec(const char *format, t_spec *spec);
int				ft_printf(const char *format, ...);
void			set_spec(t_spec *spec, int count);
void			set_spec_arrs(t_spec *spec, int i, char *cur);
void			set_cont(va_list ap, t_spec *spec, int count);
int				c_num(t_spec *spec, va_list ap);
int				c_di(t_spec *spec, long nb);
int				c_s(t_spec *spec, char *str);
int				c_c(t_spec *spec, int c);
int				c_u(t_spec *spec, unsigned long c);
int				c_p(t_spec *spec, void *p);
int				c_o(t_spec *spec, unsigned long i);
int				c_x(t_spec *spec, unsigned long x, int i);
int				c_b(t_spec *spec, unsigned long b);
int				c_dd(t_spec *spec, double d);
int				c_ld(t_spec *spec, long double d);
int				print_f(const char *str, t_spec *spec, int len, int count);
int				set_width(t_spec *spec);
int				set_prec(t_spec *spec);

#endif
