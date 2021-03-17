/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:02:23 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/15 19:17:35 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (ft_isspace(s[start]))
		++start;
	end = ft_strlen(s) - 1;
	while (start < end && ft_isspace(s[end]))
		--end;
	++end;
	if ((new_str = (char *)ft_malloc(end - start + 1)) == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
