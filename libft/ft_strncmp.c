/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:22:03 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/21 20:50:46 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	const char *src1 = "Hola";
	const char *src2 = "Hola!";

	size_t	n = 4;

	int	res = ft_strncmp(src1, src2, n);
	if (res == 0)
		printf("Las primeras %zu letras son iguales. Diferencia %d\n", n, res);
	else
		printf("Las primeras %zu letras son diferentes."
		"Diferencia: %d\n", n, res);
	return 0;
}
*/