/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percenatge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:54:40 by ylagtab           #+#    #+#             */
/*   Updated: 2020/09/09 22:39:07 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_percenatge(t_conv_spec *conv_spec)
{
	int spaces;
	int zeros;

	if (conv_spec->flags & FLAG_ZERO)
		zeros = conv_spec->width - 1;
	else
		spaces = conv_spec->width - 1;
	if ((conv_spec->flags & FLAG_MINUS) == 0)
	{
		if (conv_spec->flags & FLAG_ZERO)
			ft_putnchar_fd('0', zeros, conv_spec->fd);
		else
			ft_putnchar_fd(' ', spaces, conv_spec->fd);
	}
	ft_write_buff("%", 1, conv_spec->fd);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', spaces, conv_spec->fd);
	return (conv_spec->width == 0 ? 1 : conv_spec->width);
}
