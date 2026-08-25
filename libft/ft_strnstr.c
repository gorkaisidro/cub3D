/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:14:20 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/26 09:59:01 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0'
			&& little[j] == big[i + j] && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char	*str1 = "Hello world!";
	const char	*str2 = "world";
	size_t	len = 12;
	char	*res = ft_strnstr(str1, str2, len);

	if (res != NULL)
		printf("Subcadena encontrada: %s\n", res);
	else
		printf("Subcadena no encontrada\n");
	return 0;
}
*/