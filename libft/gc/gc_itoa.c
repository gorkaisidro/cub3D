/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:19:44 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:20:04 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

static int	ft_exp(int base, int exp)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

static int	ft_digit_counter(int j)
{
	int	i;

	i = 1;
	while (j >= 10)
	{
		j /= 10;
		i++;
	}
	return (i);
}

static int	signer(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	return (sign);
}

char	*gc_itoa(int n)
{
	int		digits;
	int		sign;
	char	*str;
	int		j;

	if (n == -2147483648)
		return (gc_strdup("-2147483648"));
	sign = signer(n);
	if (sign)
		n = -n;
	digits = ft_digit_counter(n);
	str = gc_alloc((digits + sign + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	j = 0;
	while (j < digits)
	{
		str[j + sign] = (n / ft_exp(10, digits - j - 1)) % 10 + '0';
		n %= ft_exp(10, digits - j - 1);
		j++;
	}
	str[digits + sign] = 0;
	return (str);
}
