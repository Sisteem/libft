/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:03 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/18 15:34:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

static void	clean_up(va_list *ap)
{
	va_end(*ap);
	ft_autofree_all();
}

/*
	return valuew
*/
int	ft_printf(int fd, char *format, ...)
{
	va_list	ap;
	int		parse_ret;
	int		ret;

	ret = 0;
	parse_ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			parse_ret = parse_conversion(&format, &ap, fd);
			if (parse_ret == -1)
				break ;
			else
				ret += parse_ret;
			continue ;
		}
		else
			ret += ft_putchar_fd(*format++, fd);
	}
	clean_up(&ap);
	return (ter_i(parse_ret == -1, -1, ret));
}
