/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:45:37 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/21 20:44:03 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char str[] = "Hola mundo!";
	int	c = 'o';
	size_t	n = 14;

	void	*res = ft_memchr(str, c, n);

	if (res != NULL)
		printf("Carácter '%c' encontrado: \"%s\"\n", c, (char *)res);
	else
		printf("Carácter '%c' no encontrado en los primeros %zu bytes.\n", c, n);
	return 0;
}
*/