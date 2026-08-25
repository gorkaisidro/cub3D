/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:00 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/27 19:13:51 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main()
{
	t_list	*nodo1 = ft_lstnew("Gorka");
	t_list	*nodo2 = ft_lstnew("Isidro");
	t_list	*nodo3 = ft_lstnew("Matxi");

	nodo1->next = nodo2;
	nodo2->next = nodo3;

	t_list	*ultimo = ft_lstlast(nodo1);
	if (ultimo)
		printf("Último: %s\n", (char *)ultimo->content);
	else
		printf("Vacia");
	free(nodo1);
	free(nodo2);
	free(nodo3);
	return 0;
}
*/