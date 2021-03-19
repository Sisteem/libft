/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/12 14:11:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

int			vector_push(t_vector *vector, void *element)
{
	if (!vector || !element)
		return (-1);
	if (vector->length == vector->capacity)
		vector_grow(vector);
	ft_memcpy(vector->array + vector->length * vector->element_size, element,
		vector->element_size);
	vector->length++;
	return (0);
}
