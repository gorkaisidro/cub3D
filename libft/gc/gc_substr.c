/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:24:24 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:24:40 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

char	*gc_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	writable;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (gc_strdup(""));
	writable = len;
	if (s_len - start < len)
		writable = s_len - start;
	sub = gc_alloc(writable + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, writable + 1);
	return (sub);
}
