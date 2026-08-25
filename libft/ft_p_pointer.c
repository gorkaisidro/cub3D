/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:12:41 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:33 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_hex_pointer(unsigned long long num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (ft_p_char('0'));
	if (num >= 16)
		size += ft_p_hex_pointer(num / 16);
	if ((num % 16) < 10)
		size += ft_p_char((num % 16) + '0');
	else
		size += ft_p_char((num % 16) - 10 + 'a');
	return (size);
}

int	ft_p_pointer(void *ptr)
{
	int		size;

	size = 0;
	if (ptr == NULL)
		size += ft_p_string("(nil)");
	else
	{
		size += ft_p_string("0x");
		size += ft_p_hex_pointer((unsigned long long)ptr);
	}
	return (size);
}
