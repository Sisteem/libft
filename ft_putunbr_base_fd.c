/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:04 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/14 12:31:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_base_fd(unsigned long long n, int base, int is_upper, int fd)
{
	int					ret;
	static const char	*lower_base = "0123456789abcdef";
	static const char	*upper_base = "0123456789ABCDEF";

	ret = 0;
	if (n / base)
		ret += ft_putunbr_base(n / base, base, is_upper);
	ft_putchar_fd(is_upper ? upper_base[n % base] : lower_base[n % base], fd);
	return (ret + 1);
}
