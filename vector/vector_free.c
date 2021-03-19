/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:33:00 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/12 14:11:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

void		vector_free(t_vector *vector)
{
	size_t i;

	if (vector->free_element)
	{
		i = 0;
		while (i < vector->length)
			vector->free_element(vector->array + i++ * vector->element_size);
	}
	free(vector->array);
	free(vector);
}
