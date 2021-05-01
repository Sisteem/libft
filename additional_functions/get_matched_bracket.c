/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matched_bracket.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:19:16 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/05/01 14:10:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function will give you the matched bracket of the first character if
** this character is set in the bracket variable if not it will return NULL
** if you want to escape character Preceded by \ just activate the flag escaping
** you must set bracket variable like this "(){}''[]"
*/

#include "../libft.h"

int	get_bracket_index(char c, const char *bracket)
{
	int	i;

	i = 0;
	while (bracket[i])
	{
		if (c == bracket[i])
			return (i);
		i += 2;
	}
	return (-1);
}

char	*skip_bracket(char *str, const char *bracket, int index, int escaping)
{
	while (*str)
	{
		if (escaping && *str == '\\')
			str++;
		else if (*str == bracket[index + 1])
			break ;
		str++;
	}
	return (str);
}

void	try_skip_bracket(char **str, const char *bracket, int escaping)
{
	int	i;

	i = get_bracket_index(**str, bracket);
	if (i != -1)
		*str = skip_bracket(*str + 1, bracket, i, escaping);
}

char	*get_matched_bracket(char *str, const char *bracket,
													char *to_skip, int escaping)
{
	int	bracket_count;
	int	bracket_index;

	bracket_count = 1;
	bracket_index = get_bracket_index(*str, bracket);
	if (bracket_index != -1 && str++)
	{
		while (*str && bracket_count)
		{
			if (to_skip && ft_isinstr(*str, to_skip))
				;
			else if (escaping && *str == '\\')
				str++;
			else if (*str == bracket[bracket_index])
				bracket_count++;
			else if (*str == bracket[bracket_index + 1])
				bracket_count--;
			else
				try_skip_bracket(&str, bracket, escaping);
			if (bracket_count && *str)
				str++;
		}
	}
	return (ter_p(*str == bracket[bracket_index + 1], str, NULL));
}
