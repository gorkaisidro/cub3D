/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:49:30 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/20 20:49:44 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint8_t	get_r(uint32_t rgba)
{
	return (rgba & 0xFF);
}

uint8_t	get_g(uint32_t rgba)
{
	return ((rgba >> 8) & 0xFF);
}

uint8_t	get_b(uint32_t rgba)
{
	return (rgba >> 16 & 0xFF);
}

uint8_t	get_a(uint32_t rgba)
{
	return ((rgba >> 24) & 0xFF);
}

uint32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
