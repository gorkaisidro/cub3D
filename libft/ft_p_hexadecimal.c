/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_hexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:18:40 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:23 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_hexadecimal(unsigned int num, const char c)
{
	int	size;

	size = 0;
	if (num == 0)
		return (ft_p_char('0'));
	if (num >= 16)
		size += ft_p_hexadecimal(num / 16, c);
	if ((num % 16) < 10)
		size += ft_p_char((num % 16) + '0');
	else
	{
		if (c == 'x')
			size += ft_p_char((num % 16) - 10 + 'a');
		else if (c == 'X')
			size += ft_p_char((num % 16) - 10 + 'A');
	}
	return (size);
}
