/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:14:25 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:14:33 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	vec_resize(t_vec *src, size_t target_len)
{
	t_vec	dst;

	if (!src)
		return (-1);
	else if (!src->memory)
		return (vec_new(src, target_len, src->elem_size));
	else if (vec_new(&dst, target_len, src->elem_size) < 0)
		return (-1);
	ft_memcpy(dst.memory, src->memory, src->len * src->elem_size);
	dst.len = src->len;
	vec_free(src);
	*src = dst;
	return (1);
}
