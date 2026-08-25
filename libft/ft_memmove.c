/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:52:04 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/21 20:45:30 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest_cpy == src_cpy)
		return (dest);
	if (dest_cpy > src_cpy && dest_cpy < src_cpy + n)
	{
		while (n-- > 0)
			dest_cpy[n] = src_cpy[n];
	}
	else
	{
		while (n-- > 0)
		{
			*dest_cpy++ = *src_cpy++;
		}
	}
	return (dest);
}
/*
int main()
{
    char    str1[] = "Hello, world!";
    char    str2[20];
    char    str3[] = "Hello, world!";
    char    str4[20];

    ft_memmove(str2, str1, 5);
    printf("Copia nomral: %s\n", str2);
    memmove(str4, str3, 5);
    printf("Copia nomral: %s\n", str4);

    ft_memmove(str1 + 7, str1, 5);
    printf("Copia con solapamiento: %s\n", str1);
    memmove(str3 + 7, str3, 5);
    printf("Copia con solapamiento: %s\n", str3);
    return 0;
}
*/