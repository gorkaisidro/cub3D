/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:12:08 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/15 19:37:46 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	const char	*src = "Hola mundo!";
	char	c = 'H';

	char	*res = ft_strrchr(src, c);
	if (res != NULL)
		printf("Útima ocurrencia de %c encontrada en: %s\n", c, res);
	else
		printf("Carácter '%c' no encontrado en la cadena.\n", c);
	return 0;
}
*/