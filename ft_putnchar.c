/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:47:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/09/09 22:22:58 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnchar(char c, int n)
{
	int ret;

	ret = n;
	while (n--)
		ft_write_buff(&c, 1, 1);
	return (ret);
}
