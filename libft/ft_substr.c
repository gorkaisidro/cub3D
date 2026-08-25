/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:42:13 by gisidro-          #+#    #+#             */
/*   Updated: 2025/11/13 15:32:14 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	max_len;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	max_len = ft_strlen(s) - start;
	if (len > max_len)
		len = max_len;
	str = malloc((len + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	const char		*str = "Hola Gorka!";
	unsigned int	start = 9;
	size_t			len = 5;

	char			*subStr = ft_substr(str, start, len);

	if (subStr)
	{
		printf("%s\n", subStr);
		free(subStr);
	}
	else
		printf("Error");
	return 0;
}
	*/