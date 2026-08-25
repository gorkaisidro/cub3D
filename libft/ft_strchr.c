/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:34:17 by gisidro-          #+#    #+#             */
/*   Updated: 2025/11/13 16:58:42 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	b;
	size_t			i;

	b = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == b)
			return (&((char *)s)[i]);
		i++;
	}
	if (b == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}
/*
int	main()
{
	const char	*text = "Hola Gorka";
	char	*res = ft_strchr(text, 'G');

	if (res)
		printf("Encontrada: %c\n", *res);
	else
		printf("Letra no encontrada");
	return 0;
}
*/