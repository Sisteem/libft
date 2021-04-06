/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:19:41 by ylagtab           #+#    #+#             */
/*   Updated: 2021/04/06 15:42:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl(char const *s)
{
	int	size;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	ft_write_buff((char *)s, size, 1);
	ft_write_buff("\n", 1, 1);
	return (size + 1);
}
