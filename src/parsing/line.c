/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:07:58 by gisidro-          #+#    #+#             */
/*   Updated: 2026/06/01 18:13:33 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	line_is_only_spaces(char *line)
{
	size_t	count;
	char	*original;

	count = 0;
	original = line;
	while (*line)
	{
		if (*line == ' ')
			count++;
		line++;
	}
	if (ft_strlen(original) == count)
		return (true);
	return (false);
}

bool	is_map_line(char *line)
{
	while (*line)
	{
		if (!valid_character(*line))
			return (false);
		line++;
	}
	return (true);
}

bool	split_line(char *line, char **key, char **rest)
{
	char	*trimmed;
	char	*sep;

	trimmed = gc_strtrim(line, " \t\n\r");
	if (!trimmed)
		return (false);
	sep = trimmed;
	while (*sep && !ft_isspace(*sep))
		sep++;
	if (!*sep)
		return (false);
	*sep = '\0';
	sep++;
	while (ft_isspace(*sep))
		sep++;
	if (!*sep)
		return (false);
	*key = gc_strdup(trimmed);
	*rest = gc_strtrim(sep, " \t\n\r");
	return (*key && *rest);
}
