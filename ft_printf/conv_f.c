/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/14 12:49:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(t_conv_spec *conv_spec, t_float_specs *f_specs)
{
	int		width;
	int		precision;
	int		len;
	int		is_point_printed;
	int		is_sign_printed;

	precision = conv_spec->precision;
	width = conv_spec->width;
	is_point_printed = ((conv_spec->flags & FLAG_HASH) || (precision != 0)) &&
		f_specs->float_type != NAN && f_specs->float_type != INF;
	is_sign_printed = ((f_specs->ldbl).s.sign ||
		(conv_spec->flags & (FLAG_PLUS | FLAG_SPACE))) &&
		f_specs->float_type != NAN;
	len = 3;
	if (f_specs->float_type == FLOAT || f_specs->float_type == ZERO)
		len = f_specs->whole->length + precision + is_point_printed;
	width = width - len - is_sign_printed;
	return (width > 0 ? width : 0);
}

static int	fill_float_parts(t_conv_spec *conv_spec, t_float_specs *f_specs)
{
	int		exp;

	exp = f_specs->ldbl.s.e - 16383;
	f_specs->whole = NULL;
	f_specs->frac = NULL;
	conv_spec->precision = conv_spec->is_pset ? conv_spec->precision : 6;
	if ((f_specs->float_type = check_float_type(conv_spec, f_specs)) != FLOAT)
		return (f_specs->float_type);
	if ((f_specs->whole = get_whole(f_specs->ldbl.s.m, exp)) == NULL)
		return (-1);
	if ((f_specs->frac = get_fraction(f_specs->ldbl.s.m, exp)) == NULL)
		return (-1);
	if (conv_spec->precision < (int)f_specs->frac->length)
		if (round_float(&(f_specs->whole), &(f_specs->frac),
						conv_spec->precision) == -1)
			return (-1);
	while ((int)f_specs->frac->length > conv_spec->precision)
	{
		f_specs->frac->length--;
		f_specs->frac->digits++;
	}
	return (FLOAT);
}

static int	print_float(t_conv_spec *conv_spec, t_float_specs *f_specs)
{
	int		ret;

	ret = 0;
	ret += ft_bigint_print(f_specs->whole, conv_spec->fd);
	if (conv_spec->is_pset == 0 || conv_spec->precision != 0 ||
		(conv_spec->flags & FLAG_HASH))
		ret += ft_putchar_fd('.', conv_spec->fd);
	ret += ft_bigint_print(f_specs->frac, conv_spec->fd);
	ret += ft_putnchar_fd('0', conv_spec->precision - f_specs->frac->length,
		conv_spec->fd);
	return (ret);
}

int			conv_f(t_conv_spec *spec, va_list *ap)
{
	t_float_specs	f_spec;
	int				width;
	int				ret;

	ret = 0;
	f_spec.ldbl.val = read_long_double(ap, spec->length);
	if ((f_spec.float_type = fill_float_parts(spec, &f_spec)) == -1)
		return (-1);
	width = get_width(spec, &f_spec);
	if (f_spec.float_type == NAN || f_spec.float_type == INF)
		spec->flags &= ~FLAG_ZERO;
	if ((!(spec->flags & FLAG_MINUS) && !(spec->flags & FLAG_ZERO)))
		ret += ft_putnchar_fd(' ', width, spec->fd);
	if (f_spec.float_type != NAN)
		ret += print_float_prefix(spec, f_spec.ldbl.s.sign);
	if ((f_spec.float_type == FLOAT || f_spec.float_type == ZERO)
			&& (spec->flags & FLAG_ZERO))
		ret += ft_putnchar_fd('0', width, spec->fd);
	if (f_spec.float_type == INF || f_spec.float_type == NAN)
		ret += ft_putstr_fd(f_spec.float_type == INF ? "inf" : "nan", spec->fd);
	else
		ret += print_float(spec, &f_spec);
	if ((spec->flags & FLAG_MINUS))
		ret += ft_putnchar_fd(' ', width, spec->fd);
	return (ret);
}
