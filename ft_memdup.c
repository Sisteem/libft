/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:14:54 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/15 19:12:39 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*s;
	size_t			i;

	if (src == NULL || (res = (unsigned char*)ft_malloc(n)) == NULL)
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	return ((void*)res);
}
