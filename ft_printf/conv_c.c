/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:48:30 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/13 17:18:46 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_c(t_conv_spec *conv_spec, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	ft_putchar_fd(c, 1);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', conv_spec->width - 1, conv_spec->fd);
	return (ter_i(conv_spec->width, conv_spec->width, 1));
}
