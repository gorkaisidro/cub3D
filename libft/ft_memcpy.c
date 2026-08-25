/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:31:15 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/23 12:15:34 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !str)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)str)[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
    char    dest[] = "hola";
    char    str[] = "mundo";
    size_t  n = 6;

    printf("%s\n", dest);
    void    *res = ft_memcpy(dest, str, n);
    printf("%s\n", (char *)res);
}
*/