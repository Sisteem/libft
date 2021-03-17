/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:42:48 by vanderwolk        #+#    #+#             */
/*   Updated: 2021/01/15 19:21:31 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *addr, size_t old_size, size_t new_size)
{
	void	*ret_addr;

	if ((ret_addr = ft_malloc(new_size)) == NULL)
		return (NULL);
	ft_memcpy(ret_addr, addr, old_size);
	return (ret_addr);
}
