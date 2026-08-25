/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:37:47 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:38 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_unsigned(unsigned int num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (size += ft_p_char('0'));
	else if (num >= 10)
		size += ft_p_unsigned(num / 10);
	size += ft_p_char((num % 10) + '0');
	return (size);
}
