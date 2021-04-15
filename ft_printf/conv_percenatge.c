/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percenatge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:54:40 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/13 17:19:28 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_percenatge(t_conv_spec *conv_spec)
{
	int	spaces;
	int	zeros;

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
	ft_putchar_fd('%', 1);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar_fd(' ', spaces, conv_spec->fd);
	return (ter_i(conv_spec->width == 0, 1, conv_spec->width));
}
