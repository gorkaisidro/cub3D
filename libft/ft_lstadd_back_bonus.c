/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:19:34 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/27 20:00:47 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
/*
int main(void)
{
	t_list	*lista = NULL;
	t_list	*nodo1 = ft_lstnew("Hola");
	t_list	*nodo2 = ft_lstnew("Gorka");
	t_list	*nodo3 = ft_lstnew("Isidro");

	ft_lstadd_back(&lista, nodo1);
	ft_lstadd_back(&lista, nodo2);
	ft_lstadd_back(&lista, nodo3);

	t_list *temp = lista;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	free(nodo1);
	free(nodo2);
	free(nodo3);

	return 0;
}
*/