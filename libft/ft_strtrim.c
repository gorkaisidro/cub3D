/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:37:18 by gisidro-          #+#    #+#             */
/*   Updated: 2025/11/13 15:33:36 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
/*
int	main()
{
	const char	*str = "Hello world";
	const char	*set = "eHdl";
	char		*str_t = ft_strtrim(str, set);

	if (str_t)
	{
		printf("str = %s\n", str);
		printf("str_t = %s\n", str_t);
		free(str_t);
	}
	else
		printf("Error");
	return 0;
}
*/
