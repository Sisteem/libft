/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:58:27 by ylagtab           #+#    #+#             */
/*   Updated: 2021/02/14 10:24:24 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_element	*ft_element_new(void *content, size_t content_size)
{
	t_element *el;

	if ((el = (t_element *)ft_malloc(sizeof(t_element))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		el->content = NULL;
		el->content_size = 0;
		return (el);
	}
	if ((el->content = ft_malloc(content_size)) == NULL)
	{
		free(el);
		return (NULL);
	}
	el->content_size = content_size;
	ft_memcpy(el->content, content, content_size);
	return (el);
}

int					ft_vector_add(t_vector *vector, void *content,
	size_t content_size)
{
	t_element *data;

	if (vector->length == vector->capacity)
		if (ft_vector_realloc(vector, vector->capacity * 2) == -1)
			return (-1);
	data = ft_element_new(content, content_size);
	vector->array[vector->length] = data;
	vector->length = vector->length + 1;
	return (0);
}

int					ft_vector_add_at(t_vector *vector, size_t index,
						void *content, size_t content_size)
{
	t_element	**new_arr;
	t_element	*data;
	size_t		size;

	if (index > vector->length)
		return (1);
	data = ft_element_new(content, content_size);
	if (vector->length == vector->capacity)
	{
		vector->capacity *= 2;
		new_arr = (t_element**)ft_malloc(sizeof(t_element*) * vector->capacity);
		ft_memmove(new_arr, vector->array, sizeof(t_element*) * index);
	}
	else
		new_arr = vector->array;
	size = sizeof(t_element*) * (vector->length - index);
	ft_memmove(new_arr + index + 1, vector->array + index, size);
	new_arr[index] = data;
	if (new_arr != vector->array)
	{
		free(vector->array);
		vector->array = new_arr;
	}
	vector->length = vector->length + 1;
	return (0);
}
