/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:56:39 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/03 15:54:53 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_free(t_vector *vec, t_bool free_vec,
	void (*del)(void *content, size_t content_size))
{
	size_t i;

	i = 0;
	if (vec == NULL)
		return ;
	while (i < vec->length)
	{
		if (del)
			del(vec->array[i]->content, vec->array[i]->content_size);
		ft_memdel((void**)&(vec->array[i]));
		++i;
	}
	free(vec->array);
	if (free_vec == TRUE)
		free(vec);
}
