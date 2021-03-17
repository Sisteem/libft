/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autoalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:30:03 by ylagtab           #+#    #+#             */
/*   Updated: 2019/04/20 01:59:21 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alloc_list *g_allocs;

void	ft_autofree_all(void)
{
	t_alloc_list	*tmp;

	while (g_allocs)
	{
		tmp = g_allocs;
		g_allocs = g_allocs->next;
		free(tmp->address);
		free(tmp);
	}
	g_allocs = NULL;
}

void	*ft_autoalloc(size_t size)
{
	void			*ptr;
	t_alloc_list	*node;
	t_alloc_list	*tmp;

	if ((ptr = ft_memalloc(size)) == NULL ||
			(node = (t_alloc_list*)ft_memalloc(sizeof(t_alloc_list))) == NULL)
	{
		free(ptr);
		ft_autofree_all();
		return (NULL);
	}
	node->address = ptr;
	if (g_allocs == NULL)
		g_allocs = node;
	else
	{
		tmp = g_allocs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (ptr);
}
