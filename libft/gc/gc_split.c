/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:21:48 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:22:03 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

static size_t	word_counter(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static int	splitter(char **words, char const *s, char c, size_t q_words)
{
	size_t	i;
	char	*stop;

	i = 0;
	while (i < q_words && s)
	{
		while (*s == c)
			s++;
		stop = ft_strchr(s, c);
		if (!stop)
			stop = ft_strchr(s, 0);
		words[i] = gc_substr(s, 0, stop - s);
		if (!words[i])
			return (1);
		s = stop + (*stop != 0);
		i++;
	}
	words[i] = NULL;
	return (0);
}

char	**gc_split(char const *s, char c, int *n)
{
	size_t	q_words;
	char	**words;

	q_words = word_counter(s, c);
	*n = (int)q_words;
	words = gc_alloc((q_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	if (splitter(words, s, c, q_words))
		return (NULL);
	return (words);
}
