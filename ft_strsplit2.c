/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:56:23 by mel-idri          #+#    #+#             */
/*   Updated: 2021/04/30 16:23:48 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			count_words(const char *s, char c)
{
	int		words;
	size_t	i;
	int		is_in_word;

	i = 0;
	words = 0;
	is_in_word = 0;
	while (s[i])
	{
		if (!is_in_word && s[i] != c)
		{
			is_in_word = 1;
			words++;
		}
		else if (is_in_word && s[i] == c)
			is_in_word = 0;
		i++;
	}
	return (words);
}

static unsigned int	char_count(char const *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
		if (s[i++] == c)
			count++;
	return (count);
}

static char			**split_reject_empty(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	i = 0;
	j = 0;
	if ((words = (char **)ft_memalloc((count_words(s, c) + 1) * sizeof(char *)))
			== NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		words[j++] = end - start > 0 ? ft_strsub(s, start, end - start) : NULL;
	}
	return (words);
}

static char			**split_allow_empty(char const *str, char c)
{
	size_t			i;
	unsigned int	word_count;
	char			*start;
	char			*end;
	char			**words;

	i = 0;
	word_count = char_count(str, c) + 1;
	words = ft_memalloc(sizeof(char*) * (word_count + 1));
	i = 0;
	start = (char*)str;
	while (1)
	{
		end = start;
		while (*end && *end != c)
			end++;
		words[i++] = ft_strndup(start, end - start);
		start = *end ? end + 1 : end;
		if (*start == '\0' && *end == '\0')
			break ;
	}
	words[i] = NULL;
	return (words);
}

char				**ft_strsplit2(char const *s, char c,
	t_split_mode split_mode)
{
	if (s == NULL)
		return (NULL);
	if (split_mode == ALLOW_EMPTY_WORD)
		return (split_allow_empty(s, c));
	else
		return (split_reject_empty(s, c));
}
