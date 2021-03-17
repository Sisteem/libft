/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:04 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/15 08:37:09 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunbr_fd(unsigned long long n, int fd)
{
	int ret;

	ret = 0;
	if (n / 10)
		ret += ft_putunbr(n / 10);
	return (ret + ft_putchar_fd(n % 10 + '0', fd));
}
