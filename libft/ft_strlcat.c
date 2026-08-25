/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:17:53 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/21 20:48:19 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dsize <= dst_len)
		return (dsize + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i < dsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
int main()
{
    char        dest[7] = "Hola_";
    const char  *src = "Gorka!";
    size_t      res = ft_strlcat(dest, src, sizeof(dest));

    printf("Dest: %s\n", dest);
    printf("Longitud total: %zu\n", res);
    return 0;
}
*/