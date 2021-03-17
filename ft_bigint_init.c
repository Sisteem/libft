/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:07:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/27 22:07:10 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint	*ft_bigint_new(unsigned int size)
{
	t_bigint	*bg_int;

	if ((bg_int = (t_bigint *)ft_autoalloc(sizeof(t_bigint))) == NULL)
		return (NULL);
	bg_int->length = size;
	if ((bg_int->digits = (char *)ft_autoalloc(size)) == NULL)
		return (NULL);
	return (bg_int);
}

t_bigint	*ft_bigint_from_uint128(__uint128_t unbr)
{
	int			len;
	int			i;
	t_bigint	*bg_int;

	len = ft_nbrlen(unbr);
	if ((bg_int = ft_bigint_new(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bg_int->digits[i] = unbr % 10;
		unbr /= 10;
		i++;
	}
	return (bg_int);
}
