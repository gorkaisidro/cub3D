/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:29:39 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/12 16:30:44 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	if (dst != NULL && src != NULL && dsize != 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int main()
{
    char    src[] = "Hello, world!";
    char    dest[10];
    size_t res = ft_strlcpy(dest, src, 10);

    printf("Dest: %s\n", dest);
    printf("Longitud de src: %zu\n", res);
    return 0;
}
*/