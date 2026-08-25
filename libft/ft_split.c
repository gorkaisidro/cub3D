/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:49:02 by gisidro-          #+#    #+#             */
/*   Updated: 2025/11/13 15:33:54 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, char c, size_t *pos)
{
	size_t	start;
	size_t	end;
	char	*word;

	while (s[*pos] == c)
		(*pos)++;
	start = *pos;
	while (s[*pos] && s[*pos] != c)
	{
		(*pos)++;
	}
	end = *pos;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[start], end - start + 1);
	return (word);
}

static void	ft_strs_free(char **strs, int count)
{
	while (count >= 0)
	{
		free(strs[count]);
		count--;
	}
	free (strs);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	count;
	size_t	pos;

	count = 0;
	if (!s)
		return (NULL);
	count = ft_count_word(s, c);
	strs = malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count)
	{
		strs[i] = ft_get_word(s, c, &pos);
		if (!strs[i++])
		{
			ft_strs_free(strs, i - 1);
			return (NULL);
		}
	}
	strs[count] = NULL;
	return (strs);
}
/*
int	main()
{
	const char	*str = "";
	char		c = 'z';
	int			i = 0;
	char		**res = ft_split(str, c);

	if (!res)
		return 1;
	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return 0;
}
*/