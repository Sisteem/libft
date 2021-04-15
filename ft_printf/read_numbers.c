/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:31:16 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/13 16:03:56 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

__int64_t	read_int(va_list *ap, t_length len)
{
	if (len == L)
		return (va_arg(*ap, long));
	else if (len == LL)
		return (va_arg(*ap, long long));
	else if (len == H)
		return ((short)va_arg(*ap, int));
	else if (len == HH)
		return ((char)va_arg(*ap, int));
	return (va_arg(*ap, int));
}

__uint64_t	read_uint(va_list *ap, t_length len)
{
	if (len == L)
		return (va_arg(*ap, unsigned long));
	else if (len == LL)
		return (va_arg(*ap, unsigned long long));
	else if (len == H)
		return ((unsigned short)va_arg(*ap, unsigned int));
	else if (len == HH)
		return ((unsigned char)va_arg(*ap, unsigned int));
	return (va_arg(*ap, unsigned int));
}

long double	read_long_double(va_list *ap, t_length len)
{
	if (len == CAPITAL_L)
		return (va_arg(*ap, long double));
	return ((long double)va_arg(*ap, double));
}
