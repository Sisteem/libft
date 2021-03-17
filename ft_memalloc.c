/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:20:44 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/15 19:11:30 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			i;

	if ((res = (unsigned char*)ft_malloc(size)) == NULL)
		return (res);
	i = 0;
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)res);
}
