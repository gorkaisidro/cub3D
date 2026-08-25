/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:54:38 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/21 18:58:23 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}
/*
int main()
{
    char    str[20] = "hello world";

    printf("%s\n", str);
    ft_bzero(str, 20);
    printf("%s\n", str);
    return(0);
}
    */