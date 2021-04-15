/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_conv_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/13 15:37:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_conv_function(t_conv_spec *conv_spec, va_list *ap, int c)
{
	if (c == 'd' || c == 'i')
		return (conv_di(conv_spec, ap));
	if (c == 'u')
		return (conv_u(conv_spec, ap));
	if (c == 'c')
		return (conv_c(conv_spec, ap));
	if (c == 's')
		return (conv_s(conv_spec, ap));
	if (c == '%')
		return (conv_percenatge(conv_spec));
	return (0);
}
