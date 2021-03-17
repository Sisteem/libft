/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:06:41 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/23 10:08:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL && EXIT_ON_ALLOC_FAIL)
	{
		ft_printf(2, "Allocation Error!\n");
		exit(1);
	}
	return (ptr);
}
