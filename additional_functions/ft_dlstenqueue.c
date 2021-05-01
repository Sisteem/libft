/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstenqueue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 00:44:52 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 13:50:46 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_d_list	*ft_dlstenqueue(t_d_list **list, t_d_list *new)
{
	if (new && list && *list)
	{
		if ((*list)->tail)
			(*list)->tail->next = new;
		else
			(*list)->next = new;
		(*list)->tail = new->tail ? new->tail : new;
		return ((*list));
	}
	else if (new && list)
	{
		*list = new;
		return ((*list));
	}
	return (NULL);
}
