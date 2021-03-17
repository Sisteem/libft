/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:41:19 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/15 08:34:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int	size;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	ft_write_buff((char *)s, size, fd);
	ft_write_buff("\n", 1, fd);
	return (size + 1);
}
