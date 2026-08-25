/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:22:15 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:22:26 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

char	*gc_strdup(const char *s1)
{
	size_t	len;
	char	*dest;
	char	*result;

	len = ft_strlen(s1);
	dest = gc_alloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	result = dest;
	while (*s1)
		*dest++ = *s1++;
	*dest = 0;
	return (result);
}
