/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:28:58 by mel-idri          #+#    #+#             */
/*   Updated: 2020/05/09 22:51:18 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *new_str;

	if (s == NULL || (new_str = ft_strnew(n)) == NULL)
		return (NULL);
	return (ft_strncpy(new_str, s, n));
}
