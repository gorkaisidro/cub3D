/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 23:20:55 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:21:09 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_list	*gc_lstnew(void *content)
{
	t_list	*lstptr;

	lstptr = (gc_alloc(sizeof(t_list)));
	if (!lstptr)
		return (NULL);
	lstptr->content = content;
	lstptr->next = NULL;
	return (lstptr);
}
