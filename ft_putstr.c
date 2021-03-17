/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanderwolk <vanderwolk@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 05:40:49 by ylagtab           #+#    #+#             */
/*   Updated: 2020/09/09 22:24:18 by vanderwolk       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *str)
{
	if (str == NULL)
		return (0);
	return (ft_write_buff((char*)str, ft_strlen(str), 1));
}
