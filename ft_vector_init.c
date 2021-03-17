/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:27:26 by vanderwolk        #+#    #+#             */
/*   Updated: 2021/01/24 17:54:33 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_vector_init(t_vector *vector)
{
	vector->capacity = 1;
	vector->length = 0;
	vector->array = (t_element**)ft_malloc(sizeof(t_element*));
	if (vector->array == NULL)
		return (-1);
	return (0);
}

int			ft_vector_init_capacity(t_vector *vector, size_t capacity)
{
	if (capacity == 0)
		++capacity;
	vector->capacity = capacity;
	vector->length = 0;
	vector->array = (t_element**)ft_malloc(capacity * sizeof(t_element*));
	if (vector->array == NULL)
		return (-1);
	return (0);
}

t_vector	*ft_vector_new(void)
{
	t_vector	*v;

	v = (t_vector*)ft_malloc(sizeof(t_vector));
	if (ft_vector_init(v) == -1)
	{
		free(v);
		return (NULL);
	}
	return (v);
}

t_vector	*ft_vector_new_capacity(size_t capacity)
{
	t_vector	*v;

	v = (t_vector*)ft_malloc(sizeof(t_vector));
	if (ft_vector_init_capacity(v, capacity) == -1)
	{
		free(v);
		return (NULL);
	}
	return (v);
}
