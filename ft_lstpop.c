/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:13:53 by ylagtab           #+#    #+#             */
/*   Updated: 2019/04/10 18:16:45 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstpop(t_list **alst)
{
	t_list	*node;
	t_list	*tmp;

	if (*alst == NULL)
		return (NULL);
	if ((*alst)->next == NULL)
	{
		node = *alst;
		*alst = NULL;
		return (node);
	}
	tmp = *alst;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	return (node);
}
