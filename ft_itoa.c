/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:45:26 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/15 09:34:20 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*res;
	size_t			size;
	int				index;

	nb = n > 0 ? n : -n;
	size = ft_nbrlen(nb) + (n < 0);
	if ((res = ft_strnew(size)) == NULL)
		return (NULL);
	if (n <= 0)
		res[0] = n < 0 ? '-' : '0';
	index = size - 1;
	while (nb > 0)
	{
		res[index] = nb % 10 + '0';
		nb /= 10;
		index--;
	}
	return (res);
}
