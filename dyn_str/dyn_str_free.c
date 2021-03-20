/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:39:51 by mel-idri          #+#    #+#             */
/*   Updated: 2020/12/14 00:09:38 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

void	dyn_str_free(t_dyn_str *dyn_str)
{
	if (dyn_str == NULL)
		return ;
	ft_memdel((void**)&dyn_str->str);
	free(dyn_str);
}
