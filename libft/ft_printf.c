/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:01:14 by gisidro-          #+#    #+#             */
/*   Updated: 2025/12/04 15:34:43 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_format(va_list args, const char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_p_char(va_arg(args, int));
	else if (c == 's')
		size += ft_p_string(va_arg(args, char *));
	else if (c == 'p')
		size += ft_p_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		size += ft_p_integer(va_arg(args, int));
	else if (c == 'u')
		size += ft_p_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		size += ft_p_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == '%')
		size += ft_p_char('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			size += ft_s_format(args, format[i + 1]);
			i++;
		}
		else
		{
			size += ft_p_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (size);
}
