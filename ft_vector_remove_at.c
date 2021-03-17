/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_remove_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:27:40 by ylagtab           #+#    #+#             */
/*   Updated: 2021/02/16 11:18:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_remove_at(t_vector *vector, size_t index,
	void (*del)(void *content, size_t content_size))
{
	t_element	*data;
	size_t		elements_size;

	if (index >= vector->length)
		return (1);
	data = vector->array[index];
	if (del != NULL)
		(*del)(data->content, data->content_size);
	free(data);
	elements_size = sizeof(t_element*) * (vector->length - index - 1);
	ft_memmove(vector->array + index, vector->array + index + 1, elements_size);
	vector->array[vector->length - 1] = NULL;
	vector->length = vector->length - 1;
	if (vector->length && vector->length * 4 <= vector->capacity)
		if (ft_vector_realloc(vector, vector->capacity / 4) == -1)
			return (-1);
	return (0);
}
