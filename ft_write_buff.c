/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:03:30 by ylagtab           #+#    #+#             */
/*   Updated: 2020/09/09 22:15:48 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_buffer[BUFF_SIZE];
static int	g_buff_index;

int			ft_write_buff(char *str, size_t size, int fd)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < size)
	{
		if (g_buff_index == BUFF_SIZE)
			ft_flush_buff(fd);
		g_buffer[g_buff_index] = str[i];
		i++;
		g_buff_index++;
	}
	return (size);
}

void		ft_flush_buff(int fd)
{
	write(fd, g_buffer, g_buff_index);
	g_buff_index = 0;
}
