/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:13:08 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/04/30 16:46:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long	ft_atoi_base(const char *s, const char *s_base, int base)
{
	long long	n;
	int			m;
	int			i;

	n = 0;
	i = 0;
	m = 1;
	s = ft_skip_chars((char *)s, " \n\t\r\v", NULL);
	if ((*s == 45 || *s == 43) && ft_isinstr(s[1], s_base))
		m *= ter_i(*s++ == '-', -1, 1);
	while (ft_isinstr(*s, s_base))
		n = (n * base) + (ft_strindexof(s_base, *s++) - 1);
	return (n * m);
}