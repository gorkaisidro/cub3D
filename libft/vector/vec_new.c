/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:13:42 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:13:51 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if (!dst || !elem_size)
		return (-1);
	dst->alloc_size = init_len * elem_size;
	dst->len = 0;
	dst->elem_size = elem_size;
	if (!init_len)
		dst->memory = NULL;
	else
	{
		dst->memory = gc_alloc(dst->alloc_size);
		if (!dst->memory)
			return (-1);
	}
	return (1);
}
