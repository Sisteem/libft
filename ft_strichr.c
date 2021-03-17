/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:05:08 by ylagtab           #+#    #+#             */
/*   Updated: 2020/10/15 08:43:38 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strichr(const char *s, int c)
{
	size_t	i;
	char	ch;

	if (s == NULL)
		return (-1);
	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}
