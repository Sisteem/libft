/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:27:42 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/27 22:26:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}
