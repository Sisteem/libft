/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:47:19 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/15 19:17:04 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int i;
	int k;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (k != i)
			count++;
	}
	return (count);
}

static char	**create_table(const char *s, char c)
{
	char	**t;
	int		w_count;

	w_count = count_words((char *)s, c) + 1;
	t = (char **)ft_malloc(w_count * sizeof(char *));
	return (t);
}

static char	**free_table(char **words, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**words;

	if (s == NULL || (words = create_table(s, c)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i && (words[j++] = ft_strsub(s, start, i - start)) == NULL)
			return (free_table(words, j));
	}
	words[j] = NULL;
	return (words);
}
