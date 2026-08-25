/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:13:29 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:36 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_string(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (ft_p_string("(null)"));
	while (str[size])
		size += ft_p_char(str[size]);
	return (size);
}
