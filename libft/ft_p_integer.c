/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:27:58 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:30 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_integer(int num)
{
	int	size;

	size = 0;
	if (num == 0)
		size += ft_p_char('0');
	if (num == -2147483648)
	{
		size += ft_p_string("-2147483648");
		return (size);
	}
	if (num < 0)
	{
		size += ft_p_char('-');
		num = -num;
	}
	if (num > 0)
		size += ft_p_unsigned((unsigned int)num);
	return (size);
}
