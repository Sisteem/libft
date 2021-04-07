/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:47:09 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/07 11:30:48 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnchar_fd(char c, int n, int fd)
{
	char	*str;
	int		size;

	size = n;
	str = ft_malloc(size);
	while (n--)
		str[n] = c;
	write(fd, str, size);
	return (size);
}
