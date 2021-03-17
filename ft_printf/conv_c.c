/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:48:30 by mel-idri          #+#    #+#             */
/*   Updated: 2020/09/09 22:34:41 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_c(t_conv_spec *conv_spec, va_list *ap)
{
	char c;

	c = (char)va_arg(*ap, int);
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	ft_write_buff(&c, 1, conv_spec->fd);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	return (conv_spec->width ? conv_spec->width : 1);
}
