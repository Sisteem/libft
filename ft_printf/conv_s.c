/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 00:12:42 by mel-idri          #+#    #+#             */
/*   Updated: 2020/09/09 22:35:57 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(t_conv_spec *conv_spec, va_list *ap)
{
	int		str_len;
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	str_len = conv_spec->is_pset && conv_spec->precision < str_len ?
		conv_spec->precision : str_len;
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar_fd(' ', conv_spec->width - str_len, conv_spec->fd);
	ft_write_buff(str, str_len, conv_spec->fd);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', conv_spec->width - str_len, conv_spec->fd);
	return (conv_spec->width > str_len ? conv_spec->width : str_len);
}
