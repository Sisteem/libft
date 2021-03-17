/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:47:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/09/09 23:39:50 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnchar_fd(char c, int n, int fd)
{
	int ret;

	ret = n;
	while (n--)
		ft_write_buff(&c, 1, fd);
	return (ret);
}
