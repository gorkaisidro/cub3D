/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:49:27 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:17:48 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gc	*get_gc(void)
{
	static t_gc	gc = {NULL};

	return (&gc);
}

void	*gc_alloc(size_t size)
{
	t_gc	*gc;
	void	*ptr;
	t_list	*node;

	gc = get_gc();
	if (!size)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = ft_lstnew(ptr);
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, size);
	ft_lstadd_front(&(gc->head), node);
	return (ptr);
}

void	gc_free(void *ptr)
{
	t_gc	*gc;
	t_list	*curr;
	t_list	*prev;

	if (!ptr)
		return ;
	gc = get_gc();
	curr = gc->head;
	prev = NULL;
	while (curr)
	{
		if (curr->content == ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				gc->head = curr->next;
			free(curr->content);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	gc_free_array(int n, void **ptr_array)
{
	while (n--)
		gc_free(ptr_array[n]);
	gc_free(ptr_array);
}

void	gc_free_all(void)
{
	t_gc	*gc;
	t_list	*curr;
	t_list	*temp;

	gc = get_gc();
	curr = gc->head;
	while (curr)
	{
		temp = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = temp;
	}
	gc->head = NULL;
}
